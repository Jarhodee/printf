#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *  
 *  @fmt: The format.
 *  @fn: The function associated.
 */

struct fmt

{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmts fmt_x - Struct op
 *  
 *  @fmts: f0rmat.
 *  @fmt_x: functi0n associated.
 */

typedef struct fmts fmt_x;

int _printf(const char *formannts, ...);
int handle_print(const char *fmts, int *k,
		va_list list, char buffer[], int flags, int widths, int precisions, int sizes);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_string(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_percent(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

/* Functions to print numbers */

int print_int(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_binary(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_unsigned(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_octal(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_hexadecimal(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);
int print_hexa_upper(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

int print_hexa(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int widths, int precisions, int sizes);

/* Function to print non printable characters */

int print_non_printable(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

/* Funcion to print memory address */

int print_pointer(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

/* Funciotns to handle other specifiers */

int get_flags(const char *formannts, int *k);
int get_width(const char *formannts, int *k, va_list list);
int get_precisions(const char *formannts, int *k, va_list list);
int get_size(const char *formannts, int *k);

/*Function to print string in reverse*/

int print_reverse(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

/*Function to print a string in rot 13*/

int print_rot13string(va_list types, char buffer[],
		int flags, int widths, int precisions, int sizes);

/* widths handler */

int handle_write_char(char c, char buffer[],
		int flags, int widths, int precisions, int sizes);
int write_number(int is_positive, int ind, char buffer[],
		int flags, int widths, int precisions, int sizes);
int write_num(int ind, char bff[], int flags, int widths, int precisions,
		int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int widths, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		char buffer[],
		int flags, int widths, int precisions, int sizes);

/****************** UTILS ******************/

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int numx, int sizes);
long int convert_size_unsgnd(unsigned long int numx, int sizes);


#endif 

/* MAIN_H */
