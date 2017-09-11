# valid make options:
#  1. make
#      -Builds any needed files
#  2. make new
#      -Removes all previously built files and rebuilds
#  3. make run
#      -Builds any needed files and runs the program right away
#  4. make clean
#      -Removes all previously built files
#  5. make install
#      -installs the program and it's required directory for saving
#  6. make uninstall
#      -removes the program
#  7. make purge
#      -removes the program and any saved data

TARGET = dtpriority
DEL = -rm
.PHONY: all new clean install uninstall

all:
	+$(MAKE) -C src

new:
	+$(MAKE) -C ./ clean
	+$(MAKE) -C ./

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@

install:
	-mkdir -p $(HOME)/.$(TARGET)
	chmod 777 -R $(HOME)/.$(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

uninstall:
	-rm /usr/local/bin/$(TARGET)

purge:
	-rm -rf $(HOME)/.dtpriority
	-rm /usr/local/bin/$(TARGET)


