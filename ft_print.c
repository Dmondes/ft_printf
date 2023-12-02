#include "printf.h"

int     ft_printf(const char *format, ...)
{
        va_list args;
        int             count;

        count = 0;
        va_start(args, format);
        while (*format)
        {
                if (*format == '%')
                {
                    find_format(*format, args);
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

int     find_format(char c, va_list args)
{
        if (c == 'c')
                ft_pchar(args);
        else if (c == 's')
                ft_pstr(args);
        else if (c == 'd' || c == 'i')
                ft_pint(args);
        else if (c == 'u')
                ft_punsign(args);
        else if (c == 'p')
                ft_ppoint(args);
        else if (c == 'x')
                ft_plower(args);
        else if (c == 'X')
                ft_pupper(args);
        else if (c =='%')
                ft_ppercent(args);
}
