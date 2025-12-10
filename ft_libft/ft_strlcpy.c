/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:25:24 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:25:32 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i = 0;
    size_t src_len = 0;

    while (src[src_len])
        src_len++;

    if (dstsize == 0)
        return src_len;

    while (i < dstsize - 1 && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return src_len;
}

/* int main (void)
{
    char dest[50];

    int o = ft_strlcpy(dest, "Bonjour", 50);
    printf("%d\n", o);
    printf("%s", dest);
    return 0;
} */
