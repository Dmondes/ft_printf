#include "ft_printf.h"

int	ft_pstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_pstr("(null)"));
	while (*str)
	{
		ft_pchar(*str);
		count ++;
		str ++;
	}
	return (count);
}
