/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slidriss <slidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:15:05 by slidriss          #+#    #+#             */
/*   Updated: 2025/11/11 11:15:11 by slidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void del(void *str)
{
    free(str);
}

void print_node(void *lst)
{
    char *str;
    size_t i;
    
    str = (char *)lst;
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_node;
    t_list *current;

    if (!lst || !f)
        return (NULL);
    new_list = NULL;
    current = lst;
    while(current)
    {
        new_node = lstnew(f(current->content));
        if (!new_node)
        {
            lstclear(&new_list, del);
            return (NULL);
        }
        lstadd_back(&new_list, new_node);
        current = current->next;
    }
    return (new_list);
}
