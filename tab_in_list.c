#include "ft_push_swap.h"

t_list *ft_create_elem(void *data)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->data = atol(data);
    node->next = NULL;
    return (node);
}

void ft_lstadd_back(t_node **lst, t_node *new)
{
    t_list *current;

    if (!lst || !new)
        return ;
    if (!*lst)
        return ;
    current = *lst;
    while (current->next != NULL)
        current = current->next;
    current->next = new;
}

void tab_in_list(char **a, int size, t_list **lst)
{
    size_t  i;
    size_t  j;
    t_list  *new;

    i = 0;
    j = 0;
    while (i < size)
    {
        new = ft_create_elem(a[i]);
        ft_lstadd_back(lst, new);
        i++;
    }
    free_tab(a);
}
