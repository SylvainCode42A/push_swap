#include "../ft_printf.h"

int ft_puthex_lower_ul (unsigned long p)
{
    char *hex;
    int count;
    
    hex = "0123456789abcdef";
    count = 0;
    if (p >= 16)
        count += ft_puthex_lower_ul (p / 16);
    count += write(1, &hex[p % 16], 1);
    return (count);
}

int ft_putptr(void *ptr)
{
    unsigned long ptrr;
    int count;

    if (!ptr)
    {
        count = write (1, "0x0", 3);
        return (count);
    }
    ptrr = (unsigned long)ptr;
    count = write (1, "0x", 2);
    count += ft_puthex_lower_ul(ptrr);
    return (count);
}
