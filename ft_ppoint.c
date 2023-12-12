#include "ft_printf.h"

int	ft_rehex(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count += ft_pchar('0');
	else if (n <= 9)
		count += ft_pchar(n + '0');
	else if (n >= 10 && n <= 15)
		count += ft_pchar(n - 10 + 'a');
	else
	{
		count += ft_rehex(n / 16);
		count += ft_rehex(n % 16);
	}
	return (count);
}

int	ft_ppoint(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_pstr("(nil)");
		return (5);
	}
	count += ft_pstr("0x");
	count += ft_rehex(n);
	return (count);
}
