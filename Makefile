
TARGET = dtpriority
DEL = rm
.PHONY: new clean

all:
	+$(MAKE) -C src

new:
	+$(MAKE) -C ./ clean
	+$(MAKE) -C src clean
	+$(MAKE) -C ./

run:
	+$(MAKE) -C src
	./$(TARGET)

clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@


