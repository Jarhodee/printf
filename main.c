#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * printf project
 * main - The entry point.
 *
 * Return: Always return (0)
 *
 * */

int main(void)
{
	unsigned int uv;
	int cod;
	int cod2;
	    
	void *subr;

	cod = _printf("Let's try to printf a simple sentence.\n");
	cod2 = printf("Let's try to printf a simple sentence.\n");
	uv = (unsigned int)INT_MAX + 1024;
	subr = (void *)0x7ffe637541f0;
	_printf("length:[%d, %i]\n", cod, cod);
	printf("length:[%d, %i]\n", cod2, cod2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", uv);
	printf("Unsigned:[%u]\n", uv);
	_printf("Unsigned octal:[%o]\n", uv);
	printf("Unsigned octal:[%o]\n", uv);
	_printf("Unsigned hexadecimal:[%x, %X]\n", uv, uv);
	printf("Unsigned hexadecimal:[%x, %X]\n", uv, uv);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("subress:[%p]\n", subr);
	printf("subress:[%p]\n", subr);
	cod = _printf("Percent:[%%]\n");
	cod2 = printf("Percent:[%%]\n");
	_printf("cod:[%d]\n", cod);
	printf("cod:[%d]\n", cod2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return (0);
}
