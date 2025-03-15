CC = gcc
CFLAGS = -Wall -Wextra

OBJS = open_create.o tools.o main.o
all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) main