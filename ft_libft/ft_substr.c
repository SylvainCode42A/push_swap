/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:21:44 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:22:04 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t total;
    char *sub;
    size_t s1_len;
    
    if (!s)
        return NULL;
    s1_len = strlen(s);
    if (start >= s1_len)
        return malloc(1);
    if (s1_len - start < len)
        total = s1_len - start;
    else 
        total = len;
    sub = malloc((sizeof(char) * total) + 1);
    if (!sub)
        return NULL;
    i = 0;
    while (i < total)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

/* int main(void)
{
    char *s1 = "Bonjour";
    char *sub = ft_substr(s1, 3, 4);
    printf("%s", sub);
    return 0;
} */
