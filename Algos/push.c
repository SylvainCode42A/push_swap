#include "ft_push_swap.h"

void push_a_to_b(t_list **a, t_list **b)
{
    t_list *temp;

    if (!a || !*a)
        return ;
    temp = *a;
    *a = (*a)->next;

    *tmp->next = *b;
    *b = tmp;
    ft_printf("pb\n");
}

void push_b_to_a(t_list **a, t_list **b)
{
    t_list *temp;

    if (!b || !*b)
        return ;
    temp = *b;
    *b = (*b)->next;

    *temp->next = *a;
    *a = temp;
    ft_printf("pa\n");
}
