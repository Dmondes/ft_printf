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

int     find_format(const char  *format, int    i)
{
        if (format[i] == 'c')
                ft_pchar();
        else if (format[i] == 's')
                ft_pstr();
        else if (format[i] == 'd' || format[i] == 'i')
                ft_pint();
        else if (format[i] == 'u')
                ft_punsign();
        else if (format[i] == 'p')
                ft_ppoint();
        else if (format[i] == 'x')
                ft_plower();
        else if (format[i] == 'X')
                ft_pupper();
        else if (format[i] =='%')
                ft_ppercent();
}
