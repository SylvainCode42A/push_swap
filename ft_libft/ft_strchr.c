/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:24:56 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 12:59:39 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    size_t i = 0;

    while (s[i])
    {
        if ((unsigned char)s[i] == (unsigned char)c)
            return (char *)&s[i];
        i++;
    }
    if ((unsigned char)c == '\0')
        return (char *)&s[i];
    return NULL;
}
