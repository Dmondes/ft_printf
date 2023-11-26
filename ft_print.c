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
