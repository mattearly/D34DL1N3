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

TARGET = dtpriority
DEL = -rm
.PHONY: all new clean install

all:
	+$(MAKE) -C src

new:
	+$(MAKE) -C ./ clean
	+$(MAKE) -C ./

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@

install:
	-mkdir $(HOME)/.dtpriority
	install $(TARGET) /usr/local/bin/


