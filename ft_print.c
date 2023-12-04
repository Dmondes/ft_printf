#include "ft_printf.h"
#include "libft.h/libft.h"

int	ft_pchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_pstr(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_pchar(*str);
		count ++;
		str ++;
	}
	return (count);
}

int ft_pint(int n)
{
    int count;
	char base;
	char digit;

	count = 0;
    if (n >= 0 && n <= 9)
    {
		base = '0' + n;
        ft_pchar(base);
        return 1; // Return 1 as only one digit is printed
    }
    else
    {
        count += ft_pint(n / 10); // Accumulate the count returned by recursive calls
        digit = '0' + (n % 10);
        ft_pchar(digit);
        return count + 1; // Increment count for the last digit
    }
}

int	ft_punsign(unsigned int n)
{
	 int count;
	char base;
	char digit;

	count = 0;
	if (n < 0)
		return (0);
    if (n >= 0 && n <= 9)
    {
		base = '0' + n;
        ft_pchar(base);
        return (1); // Return 1 as only one digit is printed
    }
    else
    {
        count += ft_punsign(n / 10); // Accumulate the count returned by recursive calls
        digit = '0' + (n % 10);
        ft_pchar(digit);
        return (count + 1); // Increment count for the last digit
    }
}

int	ft_ppoint(unsigned long int n)
{
	int	count;
	
	count = 0;
	if (n <= 0)
		return (0);
	return (count);
}

int lower_hex(int n)
{
	if (n == 10)
		ft_pchar('a');
	else if (n == 11)
		ft_pchar('b');
	else if (n == 12)
		ft_pchar('c');
	else if (n == 13)
		ft_pchar('d');
	else if (n == 14)
		ft_pchar('e');
	else if (n == 15)
		ft_pchar('f');
	return (1);
}

int	ft_plower(unsigned int n)
{
	int	count;
	char base;
	char digit;

	count = 0;
	if (n >=0 && n <= 9)
	{
		base = '0' + n;
		ft_pchar(base);
		return (1);
	}
	else if (n < 16)
		return (lower_hex(n));
	 else
    {
        count += ft_plower(n / 16);
        digit = '0' + (n % 16);
        ft_pchar(digit);
        return (count + 1);
    }
}

int upper_hex(int n)
{
	if (n == 10)
		ft_pchar('A');
	else if (n == 11)
		ft_pchar('B');
	else if (n == 12)
		ft_pchar('C');
	else if (n == 13)
		ft_pchar('D');
	else if (n == 14)
		ft_pchar('E');
	else if (n == 15)
		ft_pchar('F');
	return (1);
}

int	ft_pupper(unsigned int n)
{
	int	count;
	char base;
	char digit;

	count = 0;
	if (n >=0 && n <= 9)
	{
		base = '0' + n;
		ft_pchar(base);
		return (1);
	}
	else if (n < 16)
		return (upper_hex(n));
	 else
    {
        count += ft_plower(n / 16);
        digit = '0' + (n % 16);
        ft_pchar(digit);
        return (count + 1);
    }
}

int	ft_ppercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	find_format(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_pchar(va_arg(args, int));
	else if (c == 's')
		count += ft_pstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_pint(va_arg(args, int));
	else if (c == 'u')
		count += ft_punsign(va_arg(args, unsigned int));
	else if (c == 'p')
		count += ft_ppoint(va_arg(args, unsigned long int));
	else if (c == 'x')
		count += ft_plower(va_arg(args, unsigned int));
	else if (c == 'X')
		count += ft_pupper(va_arg(args, unsigned int));
	else if (c == '%')
		count += ft_ppercent();
	return (count);
}

int ft_printf(const char *format, ...) 
{
    va_list args;
    int count = 0;

    if (format == NULL) 
    {
        return (-1);
    }

    va_start(args, format);
    while (*format) 
    {
        if (*format == '%') 
        {
            format++;
            count += find_format(*format, args);
        } else 
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }
    va_end(args);
    return count;
}
