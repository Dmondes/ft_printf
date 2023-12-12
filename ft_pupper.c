#include "ft_printf.h"

int	upper_hex(int n)
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
		return (upper_hex(n));
	else
	{
		count += ft_pupper(n / 16);
		ft_pupper(n % 16);
		return (count + 1);
	}
}
