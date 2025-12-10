/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:24:24 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 12:53:38 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d;
    const unsigned char *s;

    if (!dst && !src)
        return (NULL);
    d = (unsigned char *)src;
    s = (const unsigned char *)dst;
    if (d > s)
    {
        while (len--)
            d[len] = s[len];   // copie de droite à gauche
    }
    else
    {
        size_t i = 0;
        while (i < len)
        {
            d[i] = s[i];       // copie de gauche à droite
            i++;
        }
    }
    return (dst);
}
