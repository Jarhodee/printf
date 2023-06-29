#include "main.h"

/**
 * handle_write_charss - it prints a string
 * @g: the char types.
 * @buffer: Buffer array to handle print
 * @flg:  Calculates active flg.
 *  wid_th: get wid_th.
 *  @is_precision: is_precision specifier
 *  @sizes: Size specifier
 *   
 *   Return: Number of chars printed.
 *   */

int handle_write_charss(char g, char buffer[],
		int flg, int wid_th, int is_precision, int sizes)
{
	int y = 0;
	char padd = ' ';

	UNUSED(is_precision);
	UNUSED(sizes);

	if (flg & F_ZERO)
		padd = '0';

	buffer[y++] = g;
	buffer[y] = '\0';

	if  (wid_th > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (y = 0; y < wid_th - 1; y++)
			buffer[BUFF_SIZE - y - 2] = padd;

		if (flg & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - y - 1], wid_th - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - y - 1], wid_th - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_num - Prints a string
 * @is_negative: it list a of arguments
 * @indx: char type
 * @buffer: Buffer array to handle print
 * @flg:  it calculates active flg
 * wid_th: get wid_th.
 * @is_precision: is_precision specifier
 * @sizes: Size specifier
 *   
 * Return: the number of chars printed.
 */

int write_number(int is_negative, int indx, char buffer[],
		int flg, int wid_th, int is_precision, int sizes)
{
	int len_ght = BUFF_SIZE - indx - 1;
	char padx = ' ', extra_chs = 0;

	UNUSED(sizes);

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padx = '0';
	if (is_negative)
		extra_chs = '-';
	else if (flg & F_PLUS)
		extra_chs = '+';
	else if (flg & F_SPACE)
		extra_chs = ' ';

	return (write_num(indx, buffer, flg, wid_th, is_precision,
				len_ght, padx, extra_chs));
}

/**
   * write_num - Write a number using a bufffer
   * @indx: Indxex at which the number starts on the buffer
   * @buffer: Buffer
   * @flg: flg
   * @wid_th: wid_th
   * @prexc: is_Precision specifier
   * @len_gth: Number len_gth
   * @padx: Pading char
   * @extra_d: Extra char
   * Return: Number of printed chars.
   */

int write_num(int indx, char buffer[],
		int flg, int wid_th, int prexc,
		int len_gth, char padx, char extra_d)
{
	int i, padx_start = 1;

	if (prexc == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && wid_th == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prexc == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = padx = ' '; /* wid_th is displayed with padding ' ' */
	if (prexc > 0 && prexc < len_gth)
		padx = ' ';
	while (prexc > len_gth)
		buffer[--indx] = '0', len_gth++;
	if (extra_d != 0)
		len_gth++;
	if ( wid_th > len_gth)
	{
		for (i = 1; i < wid_th - len_gth + 1; i++)
			buffer[i] = padx;
		buffer[i] = '\0';
		if (flg & F_MINUS && padx == ' ')/* This asign extra char to left of buffer */
		{
			if (extra_d)
				buffer[--indx] = extra_d;
			return (write(1, &buffer[indx], len_gth) + write(1, &buffer[1], i - 1));
		}
		else if (!(flg & F_MINUS) && padx == ' ')/* extra char to left of buff */
		{
			if (extra_d)
				buffer[--indx] = extra_d;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[indx], len_gth));
		}
		else if (!(flg & F_MINUS) && padx == '0')/* extra char to left of padx */
		{
			if (extra_d)
				buffer[--padx_start] = extra_d;
			return (write(1, &buffer[padx_start], i - padx_start) + 
					write(1, &buffer[indx], len_gth - (1 - padx_start)));
		}
	}
	if (extra_d)
		buffer[--indx] = extra_d;
	return (write(1, &buffer[indx], len_gth));
}

/**
 * write_unsgnd - it writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @indx: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flg: flg specifiers
 * @wid_th: wid_th specifier
 * @is_precision: is_Precision specifier
 * @sizes: Size specifier
 *  
 *  Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int indx,
		char buffer[],
		int flg, int wid_th, int is_precision, int sizes)
{

	/* number is stored at the bufer's right and starts at position i */

	int len_gth = BUFF_SIZE - indx - 1, i = 0;
	char padx = ' ';

	UNUSED(is_negative);
	UNUSED(sizes);

	if (is_precision == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (is_precision > 0 && is_precision < len_gth)
		padx = ' ';

	while (is_precision > len_gth)
	{
		buffer[--indx] = '0';
		len_gth++;
	}

	if ((flg & F_ZERO) && !(flg & F_MINUS))
		padx = '0';

	if ( wid_th > len_gth)
	{
		for (i = 0; i < wid_th - len_gth; i++)
			buffer[i] = padx;

		buffer[i] = '\0';

		if (flg & F_MINUS) /* Asign extra char to left of buffer [buffer>padx]*/
					{
						return (write(1, &buffer[indx], len_gth) + write(1, &buffer[0], i));
								}
		else /* Asign extra char to left of padding [padx>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[indx], len_gth));
		}
	}

	return (write(1, &buffer[indx], len_gth));
}

/**
 * write_pointer - it write a memory address
 * @buffer: Arrays of chars
 * @indx: Index at which the number starts in the buffer
 * @len_gth: Length of number
 * @wid_th:  wid_th specifier
 * @flg: flg specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Indxex at which padding should start
 *  
 *  Return: Number of written chars.
 */

int write_pointer(char buffer[], int indx, int len_gth,
		int wid_th, int flg, char padd, char extra_c, int padd_start)
{
	int c;

	if  (wid_th > len_gth)
	{
		for (c = 3; c < wid_th - len_gth + 3; c++)
			buffer[c] = padd;
		buffer[c] = '\0';
		if (flg & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[indx], len_gth) + write(1, &buffer[3], c - 3));
		}
		else if (!(flg & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (extra_c)
				buffer[--indx] = extra_c;
			return (write(1, &buffer[3], c - 3) + write(1, &buffer[indx], len_gth));
		}
		else if (!(flg & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], c - padd_start) +
					write(1, &buffer[indx], len_gth - (1 - padd_start) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (extra_c)
		buffer[--indx] = extra_c;
	return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}
