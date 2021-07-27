#include <stdio.h>
#include "holberton.h"
int main(int argc, char *argv[])
{
	_printf(argv[0]);
	printf(\n);
	printf(argv[0]);
	_printf("\nhello\n");
	printf("hello\n");
	_printf("test strings %s with integer %i and %% test\n", argv[0], argc);
	printf("test strings %s with integer %i and %% tests", argv[0], argc);
}

