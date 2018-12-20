CC=gcc
CFLAGS=-I .


all: route_finder

route_finder: route_finder.o node.o link.o
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS)
	
route_finder.c: link.h node.h
node.c:  link.h node.h
link.c:  link.h node.h