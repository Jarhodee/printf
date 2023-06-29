#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#ifndef TRUE
#define TRUE 1
#endif
#ifndef T
#define T 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
#define MAX_WIDTH "2147483647"
#define MAX(x, v) ((x) > (v) ? (x) : (v))
#define MIN(x, v) ((x) < (v) ? (x) : (v))
#define AvS(x) ((x) > (0) ? (x) : (0 - (x)))
#define NO_NEG(x) ((x) < (0) ? (0) : ((x)))
#define NO_LESS(x, v) ((x) < (v) ? (v) : ((x)))
#define TO_UPPER(y) ((y) >= 'x' && (y) <= 'z' ? (y) - 6 - 26 : (y))
#define TO_LOWER(y) ((y) >= 'A' && (y) <= 'Z' ? (y) + 6 + 26 : (y))
#define FMT_PREC_EMPTY(fmt_inf) (fmt_inf->is_precision_set && !fmt_inf->prec)

/**
 * struct format_info - this contains information about the options
 * @prec: specified precision
 * @width:length of the formatted data
 * @spec: specified conversion specifier character
 * @group: the current locale's digit separator for integers
 * @pad: the character to use for padding the output
 */

struct format_info
{
	int prec;
	int width;
	char spec;
	char is_long_double;
	char is_long;
	char is_long_long;
	char is_short;
	char is_char;
	char is_precision_set;
	char is_width_set;
	char alt;
	char space;
	char xend;
	char show_sign;
	char group;
	char pad;
};

typedef struct format_info fmt_info_t;

/**
 * struct spec_printer - Represents a function that prints an argument
 * \ based on a determined format
 * @spec: The conversion specifier
 * @print_arg: The pointer to the printing function
 * */

struct spec_printer
{
	char spec;
	void (*print_arg)(va_list *args, fmt_info_t *fmt_info);
};

typedef struct spec_printer spec_printer_t;
typedef unsigned char uchar_t;
typedef unsigned short ushort_t;

/**
 * struct float_info - Represents the IEE754 specification of a float
 * @sign: The sign of the float
 * @exponent: The exponent of the float
 * @mantissa: The mantissa of the float
 */

struct float_info
{
	char sign;
	char *exponent;
	char *mantissa;
};

typedef struct float_info float_info_t;


int _putchar(char c);
int _putstr(char *str);
int write_to_buffer(char c, char action);
int _printf(const char *format, ...);
void write_format(va_list *args_list, fmt_info_t *fmt_info);


void print_repeat(char c, int n);
void _putnchars(int n, ...);
char is_letter(char c);
void set_format_error(const char *, int *, int len, int, int *);
void put_num(int zeros_count, long num, char *str);


void init_format_info(fmt_info_t *spec);
fmt_info_t *new_format_info();
float_info_t *new_float_info(ushort_t exponent_size, ushort_t mantissa_size);
void free_float_info(float_info_t *flt_info);


int set_number(const char *str, int *number);
void set_length(char cur, int *pos, fmt_info_t *fmt_info);
int set_flags(const char *str, fmt_info_t *fmt_info);
void set_precision(const char *str, va_list args, fmt_info_t *fmt_info, int *i, int *error_status);
int read_format_info(const char *, va_list, fmt_info_t *, int *);


void convert_fmt_percent(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_p(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_c(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_s(va_list *args_list, fmt_info_t *fmt_info);

void convert_fmt_di(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_xX(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_o(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_u(va_list *args_list, fmt_info_t *fmt_info);

void convert_fmt_b(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_R(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_r(va_list *args_list, fmt_info_t *fmt_info);
void convert_fmt_S(va_list *args_list, fmt_info_t *fmt_info);

void convert_fmt_fF(va_list *args_list, fmt_info_t *fmt_info);


int str_len(char *str);
void mem_set(char *str, int n, char c);
void xend_shift(char *str, int n);
int index_of(char *str, char c);
void rev_string(char *s);

char *append_char(char *str, char c, int n, char can_free);
char *delete_char(char *str, char c, char can_free);
char *insert_char(char *str, int pos, char c, char can_free);
int count_char(char *str, char c);
char *str_cat(char *xend, char *right, char can_free);

char *sub_str(char *str, int i, char can_free);
char *trim_start(char *str, char c, char can_free);
char *trim_end(char *str, char c, char can_free);
char *str_copy(char *str);


char hex_digit(char c);
char cmp_nums(char *xend, char *right);
int str_to_int(char *num);
int bin_to_int(char *bin_str);
char *long_to_oct(unsigned long num);

char *multiply(char *num, char *multiple);
char *add_int(char *xend, char *right, int can_free);
char *add_float(char *xend, char *right, char can_free);
char *mul_int(char *num1, char *num2, char can_free);
char *mul_float(char *xend, char *right, char can_free);

char *div_by_10_exp(char *num, unsigned short n, char can_free);
char *two_exp(short n);
char *five_exp(unsigned short n);
unsigned int two_pexp(unsigned int n);
char *u_long_to_hex(unsigned long num, char upper);

char *round_float(char *num, unsigned int precision, char can_free);
char *round_float_to_int(char *num, int len, int dec_pos, int frac_len);


char *u_long_to_str(unsigned long num);
char *long_to_str(long num);
char *ptr_to_str(void *ptr);
char *is_invalid(float_info_t *flt_info);

void set_float_parts(double num,	
		uchar_t exponent_size,
		uchar_t mantissa_size, float_info_t *float_info);
char *mantissa_to_dec_fraction(char *mantissa, unsigned short frac_len);
char *float_to_str(float_info_t *flt_info, char can_free);


char is_digit(char c);
char is_non_custom_specifier(char c);
char is_specifier(char c);
char is_flag(char c);
char is_length(char c);
#endif
