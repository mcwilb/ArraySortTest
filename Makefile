
CC          = gcc
CLINKER     = gcc
CCC         = g++
CCLINKER    = $(CCC)
INCLUDE_DIR = 
CFLAGS      = $(INCLUDE_DIR)
CCFLAGS     = $(CFLAGS)
OPTFLAGS    = -g
LIB_PATH    =
LIB_LIST    = -lm
LIBS        = $(LIB_PATH) $(LIB_LIST)

EXEC        = speedtest
objects     = main.o

default: $(EXEC)

$(EXEC): $(objects)
	g++ -g -o $(EXEC) $(objects)

main.o : main.cc
	g++ -c main.cc -o main.o

clean :
	rm *.o
	rm $(EXEC)



