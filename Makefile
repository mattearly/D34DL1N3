
TARGET = dtpriority
DEL = rm -f

all:
	+$(MAKE) -C src


.PHONY: clean
clean:
	$(DEL) $(TARGET)
	+$(MAKE) -C src $@


