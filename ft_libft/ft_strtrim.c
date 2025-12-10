/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:21:21 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:21:25 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_in_set(char c, char const *set)
{
    int j = 0;
    while (set[j])
    {
        if (set[j] == c)
            return 1;  // trouvé dans set
        j++;
    }
    return 0;  // pas trouvé
}

char	*ft_strtrim(char const *s1, char const *set)
{
    char *trimmed;
    size_t start;
    size_t end;
    size_t i;
    
    if (!s1 || !set)
        return NULL;
    start = 0;
    while (s1[start] &&is_in_set(s1[start], set))
        start++;
    end = strlen(s1);
    while (end > start && is_in_set(s1[end - 1], set))
        end--;
    trimmed = malloc(end - start + 1);
    if (!trimmed)
        return NULL;
    i = 0;
    while (start + i < end)
    {
        trimmed[i] = s1[start + i];
        i++;
    }
    trimmed[i] = '\0';
    return (trimmed);
}

/* int main(void)
{
    char *dest;
    dest = ft_strtrim("**--abc--**", "*-");
    printf("%s", dest);
    free(dest);
    return 0;
} */
