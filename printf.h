#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const	char *format, ...);
int		ft_pchar(int c);
int		ft_pstr(char *str);
int		ft_pint(int n);
int		ft_punsign(unsigned int n);
int		ft_ppoint(unsigned long	int ptr);
int		ft_plower(unsigned int n);
int		ft_pupper(unsigned int n);
int		ft_ppercent(void);

#endif
