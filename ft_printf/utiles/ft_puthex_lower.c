#include "../ft_printf.h"

int ft_puthex_lower (unsigned int p)
{
    char *hex;
    int count;
    
    hex = "0123456789abcdef";
    count = 0;
    if (p >= 16)
        count += ft_puthex_lower (p / 16);
    count += write(1, &hex[p % 16], 1);
    return (count);
}

