/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:18:14 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:18:24 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
    size_t i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

/* int	main(void)
{
	ft_putstr_fd("Bonjour\n", 1); // écrit sur stdout (l’écran)
	ft_putstr_fd("Erreur\n", 2);  // écrit sur stderr
	return (0);
} */
