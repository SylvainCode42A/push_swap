/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:59:31 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 12:06:15 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		o;
	char	*p;

	o = 0;
	p = malloc (sizeof(char) * strlen(str)+ 1);
	while (str[o])
	{
		p[o] = str[o];
		o++;
	}
	p[o] = '\0';
	return (p);
}

/*int main()
{
        char *str = "Bonjour";
        int     i = ft_strlen(str);
        printf("%s\n", ft_strdup(str, i));
        return (0);
} */