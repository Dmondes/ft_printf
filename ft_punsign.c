#include "ft_printf.h"

int	ft_punsign(unsigned int n)
{
	int		count;
	char	base;
	char	digit;

	count = 0;
	if (n <= 9)
	{
		base = '0' + n;
		ft_pchar(base);
		return (1);
	}
	else
	{
		count += ft_punsign(n / 10);
		digit = '0' + (n % 10);
		ft_pchar(digit);
		return (count + 1);
	}
}
