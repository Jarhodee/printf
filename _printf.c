#include "main.h"

void print_buffer(char buffer[], int *buff_indxx);

/**
 * _printf - function
 * @formats: formats.
 * Return: Printed chars.
 */

int _printf(const char *formats, ...)
{
	int t, printed = 0, printed_chars = 0;
	int flg, wid_th, precisions, sizes, buff_indxx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (formats == NULL)
		return (-1);

	va_start(list, formats);

	for (t = 0; formats && formats[t] != '\0'; t++)
	{
		if (formats[t] != '%')
		{
			buffer[buff_indxx++] = formats[t];
			if (buff_indxx == BUFF_SIZE)
				print_buffer(buffer, &buff_indxx);
			/* write(1, &formats[t], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_indxx);
			flg = get_flags(formats, &t);
			wid_th = get_width(formats, &t, list);
			precisions = get_precisions(formats, &t, list);
			sizes = get_size(formats, &t);
			++t;
			printed = handle_print(formats, &t, list, buffer,
					flg, wid_th, precisions, sizes);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_indxx);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - it prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_indxx: the index at which to add the next char, it rep., the length 
 */

void print_buffer(char buffer[], int *buff_indxx)
{
		if (*buff_indxx > 0)
					write(1, &buffer[0], *buff_indxx);

			*buff_indxx = 0;
}
