CC = gcc
CCFLAGS = -Wall -ansi -std=c99

all: q1 q2 q3 q7 shell

q1: q1.c
		$(CC) $(CCFLAGS) -o q1 q1.c

q2: q2.c
		$(CC) $(CCFLAGS) -o q2 q2.c

q3: q3.c
		$(CC) $(CCFLAGS) -o q3 q3.c

q7: q7.c
		$(CC) $(CCFLAGS) -o q7 q7.c

shell: shell.c
		$(CC) $(CCFLAGS) -o shell shell.c

clean:
	rm *.o
