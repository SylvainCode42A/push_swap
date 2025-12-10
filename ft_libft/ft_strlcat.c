/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:26:05 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:26:08 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t count_all(char *dest, char *src, size_t dstsize)
{
    size_t len_src = 0;
    size_t len_dest = 0;

    while (src[len_src])
        len_src++;
    while (dest[len_dest])
        len_dest++;

    if (dstsize <= len_dest)
        return dstsize + len_src;
    return len_src + len_dest;
}

size_t ft_strlcat(char *dest, const char *src, size_t dstsize)
{
    size_t i = 0;
    size_t a = 0;
    size_t count = count_all(dest, (char *)src, dstsize);

    while (i < dstsize - 1 && dest[i])
        i++;
    while (i < dstsize - 1 && src[a])
    {
        dest[i] = src[a];
        i++;
        a++;
    }
    if (i < dstsize)
        dest[i] = '\0';

    return count;
}

/* int main (void)
{
    char dest[7] = "Bonjour";
    char *src = " tout le monde";
    int i = ft_strlcat(dest, src, 4);
    printf ("%d\n", i);
    printf ("%s", dest);
    return 0;
} */
