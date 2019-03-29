CFLAGS =-ggdb -std=c99 -pedantic -Wall -Wextra -fno-builtin 
main: mystring.c
	gcc $(CFLAGS) mystring.c -o string
