/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:17:45 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 12:11:47 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
    long nb;
    char c;
    
    nb = n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
    if (nb < 0)
    {
        write(fd, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr_fd(nb / 10, fd);
    c = nb % 10 + '0';
    write(fd, &c, 1);
}

/* int main()
{
    ft_putnbr_fd(12, 1); // terminal
    write(1, "\n", 1);
	ft_putnbr_fd(-433, 2);  // stderr
    write(1, "\n", 1);
    return 0;
} */
