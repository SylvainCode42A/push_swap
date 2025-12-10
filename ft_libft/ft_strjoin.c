/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:19:56 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:20:07 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    char *dest;
    size_t total;
    size_t len_1;
    size_t len_2;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    len_1 = strlen(s1);
    len_2 = strlen(s2);
    total = len_1 + len_2;

    dest = malloc(total + 1);
    if (!dest)
        return NULL;
    memcpy(dest, s1, len_1);
    memcpy(dest + len_1, s2, len_2);
    dest[len_1 + len_2] = '\0';
    return (dest);
}

/* int main(void)
{
    char *s = ft_strjoin("Bonjour", "");
    printf("%s", s);
    free (s);
    return 0;
} */
