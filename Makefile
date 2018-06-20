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
	chmod 644 -R $(HOME)/.$(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	rm /usr/local/bin/$(TARGET)

purge:
	-rm -rf $(HOME)/.dtpriority
	rm /usr/local/bin/$(TARGET)

help:
	@echo "valid 'make' options:"
	@echo "1. 'make'"
	@echo "  -Builds any needed files"
	@echo "2. 'make new'"
	@echo "  -Removes all previously built files and rebuilds"
	@echo "4. 'make clean'"
	@echo "  -Removes all previously built files"
	@echo "5. 'make install'"
	@echo "  -installs the program and it's required directory for saving"
	@echo "6. 'make uninstall'"
	@echo "  -removes the program"
	@echo "7. 'make purge'"
	@echo "  -removes the program and any saved data"
	