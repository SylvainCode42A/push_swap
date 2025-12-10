/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:22:48 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:22:56 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *si;
    unsigned char uc = (unsigned char)c;
    size_t i;

    i = 0;
    si = (const unsigned char *)s;
    while (i < n)
    {
        if (si[i] == uc)
            return (void *)&si[i];
        i++;
    }
    return NULL;
}
