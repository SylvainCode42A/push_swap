#include "ft_push_swap.h"

void rotate_a(t_list **a)
{
    t_list *current;
    t_list *first;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    first->next = NULL;
    *a = (*a)->next;
    current = *a;
    while (current->next)
        current = current->next;
    current->next = first;
    ft_printf("ra\n");
}

void rotate_b(t_list **b)
{
    t_list *current;
    t_list *first;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    first->next = NULL;
    *b = (*b)->next;
    current = *b;
    while (current->next)
        current->next;
    current->next = first;
    ft_printf("rb\n");
}

void rotate_a_silent(t_list **a)
{
    t_list *current;
    t_list *first;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    first->next = NULL;
    *a = (*a)->next;
    current = *a;
    while (current->next)
        current = current->next;
    current->next = first;
}

void rotate_b_silent(t_list **b)
{
    t_list *current;
    t_list *first;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    first->next = NULL;
    *b = (*b)->next;
    current = *b;
    while (current->next)
        current->next;
    current->next = first;
}

void rotate_a_b(t_list **a, t_list **b)
{
    if (!a || !*a || !(*a)->next)
        return ;
    if (!b || !*b || !(*b)->next)
        return ;
    rotate_a_silent(a);
    rotate_b_silent(b);
    ft_printf("rr\n");
}
