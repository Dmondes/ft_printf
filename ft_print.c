#include "ft_printf.h"

int	find_format(char c, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			count += find_format(*format, args);
		}
		else
		{
			write(1, format, 1);
			count ++;
		}
		format ++;
	}
	va_end(args);
	return (count);
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

int	ft_pchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pstr(char *str)
{
	int	count;

	count = 0;
	str ++;
	return (count);
}

int	ft_pint(int n)
{
	int	count;

	count = 0;
	n ++;
	return (count);
}

int	ft_punsign(unsigned int n)
{
	int	count;

	count = 0;
	n ++;
	return (count);
}

int	ft_ppoint(unsigned int n)
{
	int	count;

	count = 0;
	n ++;
	return (count);
}

int	ft_plower(unsigned int n)
{
	int	count;

	count = 0;
	n ++;
	return (count);
}

int	ft_ppercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_pupper(unsigned int n)
{
	int	count;

	count = 0;
	n ++;
	return (count);
}
