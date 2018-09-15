TARGET = dtpriority
DEL = rm -rf
.PHONY: all new clean install uninstall purge help

all:
	+$(MAKE) -C src $(TARGET)

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@

install: all
	mkdir -p $(HOME)/.$(TARGET)
	chmod 755 $(HOME)/.$(TARGET)
	+$(MAKE) -C finalize

finalize: 
	sudo install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	sudo $(DEL) /usr/local/bin/$(TARGET)

purge:
	$(DEL) $(HOME)/.$(TARGET)
	sudo $(DEL) /usr/local/bin/$(TARGET)

full-purge:
	+$(MAKE) clean
	+$(MAKE) purge

help:
	@echo "valid 'make' options:"
	@echo "'make'"
	@echo "  -builds any needed files"
	@echo "'make clean'"
	@echo "  -removes all previously built files"
	@echo "'make install'"
	@echo "  -installs the program and it's required directory for saving, will ask for root access"
	@echo "'make uninstall'"
	@echo "  -removes the install, will ask for root access"
	@echo "'make purge'"
	@echo "  -removes the install and any saved data, will ask for root access"
	@echo "'make full-purge'"
	@echo "  -removes all built files, removes the install and saved data, will ask for root access"
