#include "../ft_printf.h"

int ft_putstr(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
        count += write (1, &str[i++], 1);
    return (count);
}
