C	  := g++
C_FLAGS := -Wall -Wextra -std=c++17 -ggdb 
LIB := -L/usr/local/boost/boost_1_39_0/stage/lib -lboost_filesystem
LIB_O := -I /usr/local/boost/boost_1_39_0
OBJECTS := FibLFSR.o FibLFSR

LIBRARIES	:=
EXECUTABLE	:= test


run: FibLFSR.o
	$(C) $(C_FLAGS) -o FibLFSR FibLFSR.o
	./FibLFSR

FibLFSR: FibLFSR.o
	$(C) $(C_FLAGS) $(LIB) -o FibLFSR FibLFSR.o

FibLFSR.o:
	$(C) $(C_FLAGS) $(LIB_O) -c FibLFSR.cpp -o FibLFSR.o

clean:
	-rm FibLFSR $(OBJECTS)/*
