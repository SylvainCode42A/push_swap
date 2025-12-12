#include "ft_push_swap.h"

void swap_a(t_list **a)
{
    t_list *first;
    t_list *second;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *a = second;
    ft_printf("sa\n");
}

void swap_a_silent(t_list **a)
{
    t_list *first;
    t_list *second;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *a = second;
}

void swap_b(t_list **b)
{
    t_list *first;
    t_list *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = *b->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_printf("sb\n");
}

void swap_b_silent(t_list **b)
{
    t_list *first;
    t_list *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = *b->next;
    first->next = second->next;
    second->next = first;
    *b = second;
}

void swap_a_b(t_list **a, t_list **b)
{
    if (!a || !*a || !(*a)->next)
        return ;
    swap_a_silent(a);
    if (!b || !*b || !(*b)->next)
        return ;
    swap_b_silent(b);
    ft_printf("ss\n");
}
