# valid make options:
#  1. make
#      -Builds any needed files
#  2. make new
#      -Removes all previously built files and rebuilds
#  3. make run
#      -Builds any needed files and runs the program right away
#  4. make clean
#      -Removes all previously built files

TARGET = dtpriority
DEL = rm
.PHONY: new clean

all:
	+$(MAKE) -C src
	@echo D34DLine Task Priority build finished. Run with './dtpriority'

new:
	+$(MAKE) -C ./ clean
	+$(MAKE) -C ./

run:
	+$(MAKE) -C src
	./$(TARGET)

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@


