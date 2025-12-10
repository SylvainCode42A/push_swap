/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:40 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:20:43 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char char_to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t i;
    char *dest;

    if (!s || !f)
        return (NULL);
    i = 0;
    dest = malloc(strlen(s) + 1);
    if (!dest)
        return (NULL);
    while (s[i])
    {
        dest[i] = f(i, s[i]);
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/* int main()
{
    char *dest;
    
    dest = ft_strmapi("Bonjour", char_to_upper);
    printf("%s", dest);
    free(dest);
    return 0;
} */
