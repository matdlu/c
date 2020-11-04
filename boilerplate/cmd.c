#include <stdio.h>
#include <stdlib.h>

char const * help_str =  "help string";
#define MIN_ARG 3
#define MAX_ARG 4

int 
main(int argc, char const ** argv)
{
	--argc;
	++argv;
	
	if ( argc < MIN_ARG ) {
		puts("Not enough arguments");
		puts(help_str);
		return -1;
	}
	
	if ( argc > MAX_ARG ) {
		puts("Too many arguments");
		puts(help_str);
		return -1;
	}
	
	
	/* code */
	
}