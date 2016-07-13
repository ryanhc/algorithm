CC = g++
CFLAGS = -Wall -std=c++11 -g

SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)
EXE=$(SRC:.cpp=.exe)

.PHONY: clean

all: $(EXE)

%.exe : %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(EXE)
