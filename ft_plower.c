#include "ft_printf.h"

int	lower_hex(int n)
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
	int		count;
	char	base;

	count = 0;
	if (n <= 9)
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
		ft_plower(n % 16);
		return (count + 1);
	}
}
