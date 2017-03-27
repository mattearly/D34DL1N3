# valid make options:
#  1. make
#  2. make new
#  3. make run
#  4. make clean

TARGET = dtpriority
DEL = rm
.PHONY: new clean

all:
	+$(MAKE) -C src

new:
	+$(MAKE) -C ./ clean
	+$(MAKE) -C src clean
	+$(MAKE) -C ./ all

run:
	+$(MAKE) -C src
	./$(TARGET)

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@


