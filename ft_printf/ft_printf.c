#include "ft_printf.h"

int handle_format(char c, va_list ap)
{
    if (c == 'c')
        return ft_putchar(va_arg(ap, int));
    if (c == 's')
        return ft_putstr(va_arg(ap, char *));
    if (c == 'p')
        return ft_putptr(va_arg(ap, void *));
    if (c == 'd' || c == 'i')
        return ft_putnbr(va_arg(ap, int));
    if (c == 'u')
        return ft_putnbr_unsigned(va_arg(ap, unsigned int));
    if (c == 'x')
        return ft_puthex_lower(va_arg(ap, unsigned int));
    if (c == 'X')
        return ft_puthex_upper(va_arg(ap, unsigned int));
    if (c == '%')
        return write(1, "%", 1);

    return 0;
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int count;
    int i;

    va_start(ap, format); 
    count = 0;
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += handle_format(format[i], ap);
        }
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(ap);
    return (count);
}
