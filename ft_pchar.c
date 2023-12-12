#include "ft_printf.h"

int	ft_pchar(char c)
{
	return (write(1, &c, 1));
}
