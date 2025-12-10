/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:12:21 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:12:30 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void del(void *str)
{
    free(str);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *current;
    t_list *temp;

    if (!lst || !del)
        return ;
    current = *lst;
    while(current)
    {
        temp = current->next;
        del(current->content);
        free(current);
        current = temp;
    }
    *lst = NULL;
}
