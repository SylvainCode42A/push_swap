#include "../ft_printf.h"

int ft_puthex_upper (unsigned int p)
{
    char *hex;
    int count;
    
    hex = "0123456789ABCDEF";
    count = 0;
    if (p >= 16)
        count += ft_puthex_upper (p / 16);
    count += write(1, &hex[p % 16], 1);
    return (count);
}
