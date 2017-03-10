
TARGET = dtpriority
OBJS = runtasks.o main.o task.o
CPP = g++
CPPFLAGS = -std=c++11 -Wall -g
DEL = rm -f


$(TARGET): $(OBJS)
	$(CPP) $(OBJS) $(CPPFLAGS) -o ../$(TARGET)

.PHONY: clean
clean:
	$(DEL) $(OBJS)

.cpp.o:
	@echo BUILDING: $< -into- $@
	$(CPP) -c $< $(CPPFLAGS)

