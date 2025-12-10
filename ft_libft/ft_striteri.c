/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:19:31 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:19:35 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void char_to_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    size_t i;

    i = 0;
    if (!s || !f)
        return ;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }    
}


/* int main(void)
{
    char dest[] = "Bonjour";
    
    ft_striteri(dest, char_to_upper);
    printf("%s", dest);
    return 0;
} */
