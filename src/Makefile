# the makefile in the root folder (../Makefile) calls this one
# don't use this one on it's own


TARGET = dtpriority
OBJS = runtasks.o main.o runtasks_save_load.o
CC = g++
CCFLAGS = -std=c++11 -Wall -O0
DEL = -rm
.PHONY: clean


$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CCFLAGS) -o ../$(TARGET)


clean:
	$(DEL) $(OBJS)


.cpp.o:
	$(CC) -c $< $(CCFLAGS)



