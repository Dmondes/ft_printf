#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
        va_list args;
        int             count;

        if (format == NULL)
                return (-1);
        count = 0;
        va_start(args, format);
        while (*format)
        {
                if (*format == '%')
                {
                        format ++;
                        count += find_format(*format, args);
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
        int     count;

        count = 0;
        if (c == 'c')
                count += ft_pchar(va_arg(args, int));
        else if (c == 's')
                count += ft_pstr(va_arg(args, char *));
        else if (c == 'd' || c == 'i')
                count += ft_pint(va_arg(args, int));
        else if (c == 'u')
                count += ft_punsign(va_arg(args, unsigned int));
        else if (c == 'p')
                count += ft_ppoint(va_arg(args, unsigned long int));
        else if (c == 'x')
                count += ft_plower(va_arg(args, unsigned int));
        else if (c == 'X')
                count += ft_pupper(va_arg(args, unsigned int));
        else if (c == '%')
                count += ft_ppercent();
        return (count);
}
