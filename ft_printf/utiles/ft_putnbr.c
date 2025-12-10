#include "../ft_printf.h"

int ft_putnbr(int n)
{
    long nb;
    int count;

    count = 0;
    nb = n;
	if (nb < 0)
	{
		count += write (1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
	}
	count += write (1, &"0123456789"[nb % 10], 1);
    return (count);
}
