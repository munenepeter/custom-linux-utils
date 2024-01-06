CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb
LIBS=

ls: src/ls.c
	$(CC) $(CFLAGS) -o ls src/ls.c $(LIBS)