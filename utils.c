#include "main.h"

/**
 * print_able - this evaluates if a char is printable
 * @d: Char to be evaluated.
 *  
 *  Return: 1 if c is printable, 0 otherwise
 */

int print_able(char d)
{
	if (d >= 32 && d < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @z: Index at which to start appending.
 * @ascii_c: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_c, char buffer[], int z)
{
	char map_to[] = "0123456789ABCDEF";

	/* hexa format code is 2 digits long */

	if (ascii_c < 0)
		ascii_c *= -1;

	buffer[z++] = '\\';
	buffer[z++] = 'x';

	buffer[z++] = map_to[ascii_c / 16];
	buffer[z] = map_to[ascii_c % 16];

	return (3);
}

/**
 * is_digit - it verifies if a char is a digit
 * @d: Char variable to be evaluated
 *  
 *  Return: return 1 if c is a digit, or otherwise 0
 */

int i_digits(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - it casts a number to the specified siz_es
 * @nums: Numbers to be casted
 * @siz_es: Numbers indicating the type to be casted
 *  
 *  Return: return casted value of nums
 */

long int convert_size_number(long int nums, int siz_es)

{
	if (siz_es == X_LONG)
		return (nums);
	else if (siz_es == X_SHORT)
		return ((short)nums);

	return ((int)nums);
}

/**
 * convert_size_unsgnd - Casts a number to the specified siz_es
 * @nums: Numbers to be casted
 * @siz_es: Numbers indicating the type to be casted
 *  
 *  Return: return casted value of the nums
 */

long int convert_size_unsgnd(unsigned long int nums, int siz_es)

{
	if (siz_es == X_LONG)
		return (nums);
	else if (siz_es == X_SHORT)
		return ((unsigned short)nums);

	return ((unsigned int)nums);
}
