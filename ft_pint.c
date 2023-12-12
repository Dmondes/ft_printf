#include "ft_printf.h"

int	ft_negative(long n)
{
	ft_pchar('-');
	return (-n);
}

int	ft_pint(int n)
{
	int		count;
	char	base;
	char	digit;

	count = 0;
	if (n == -2147483648)
		return (count += ft_pstr("-2147483648"));
	if (n < 0)
	{
		n = ft_negative(n);
		count += 1;
	}
	if (n >= 0 && n <= 9)
	{
		base = '0' + n;
		ft_pchar(base);
		return (count + 1);
	}
	else
	{
		count += ft_pint(n / 10);
		digit = '0' + (n % 10);
		ft_pchar(digit);
		return (count + 1);
	}
}
