/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:06:28 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:06:37 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
    int digits;
    
    digits = 0;
    if (n <= 0)
        digits = 1;
    while (n != 0)
    {
        n = n / 10;
        digits++;
    }
    return (digits);
}

char	*ft_itoa(int n)
{
    long nb;
    int len;
    char *str;

    nb = n;
    len = ft_count_digits(n);
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    if (nb == 0)
        str[0] = '0';
    if (nb < 0)
    {
        str[0] = '-';
        nb = -nb;
    }
    while (nb)
    {
        str[--len] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return (str);
}

/* int main(void)
{
    char *str;
    
    str = ft_itoa(-1234);
    printf("%s\n", str);
    return 0;
} */