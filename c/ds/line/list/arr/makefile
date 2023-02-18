CFLAGS+= -Wall -g

all:main

main:main.o sqlist.o
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf *.o main
