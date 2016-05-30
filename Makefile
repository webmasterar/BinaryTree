ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT = 
	endif
endif

CC = gcc
CFLAGS = -msse3 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: binarytree
	$(CC) $(CFLAGS) -o binarytree$(EXT) binarytree.o main.o

binarytree:
	$(CC) $(CFLAGS) -c binarytree.c main.c

clean:
	$(RM) binarytree.o main.o binarytree$(EXT)
