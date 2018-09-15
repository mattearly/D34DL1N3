TARGET = dtpriority
DEL = -rm
.PHONY: all new clean install uninstall purge help

all:
	+$(MAKE) -C src $(TARGET)

new:
	+$(MAKE) clean
	+$(MAKE) all

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@

install: all
	mkdir -p $(HOME)/.$(TARGET)
	chmod 755 $(HOME)/.$(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm /usr/local/bin/$(TARGET)

purge:
	-rm -rf $(HOME)/.dtpriority
	rm /usr/local/bin/$(TARGET)

help:
	@echo "valid 'make' options(use sudo as needed):"
	@echo "'make'"
	@echo "  -Builds any needed files"
	@echo "'make new'"
	@echo "  -Removes all previously built files and rebuilds"
	@echo "'make clean'"
	@echo "  -Removes all previously built files"
	@echo "'make install'"
	@echo "  -installs the program and it's required directory for saving"
	@echo "'make uninstall'"
	@echo "  -removes the program"
	@echo "'make purge'"
	@echo "  -removes the program and any saved data"
	
