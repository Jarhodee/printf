#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flg: this calculates active flag
 * @wid_th: get wid_th.
 * @prexi: Preciesion specification
 * @sizex: Sizes specifier
 * Return: return 1 or 2;
 * */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flg, int wid_th, int prexi, int sizex)
{
	int i, x_len = 0, printed_chars = -1;
	fmt_x fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flg, wid_th, prexi, sizex));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		x_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			x_len += write(1, " ", 1);
		else if (wid_th)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		x_len += write(1, &fmt[*ind], 1);
		return (x_len);
	}
	return (printed_chars);
}
