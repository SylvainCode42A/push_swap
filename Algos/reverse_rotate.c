#include "ft_push_swap.h"

void reverse_rotate_a(t_list **a)
{
    t_list *prev;
    t_list *last;

    if (!a || !*a || !(*a)->next)
        return ;
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
    ft_printf("rra\n");
}

void reverse_rotate_b(t_list **b)
{
    t_list *last;
    t_list *prev;

    if (!b || !*b || !(*b)->next)
        return ;
    last = *b;
    prev = NULL;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    ft_printf("rrb\n");
}

void reverse_rotate_a_silent(t_list **a)
{
    t_list *prev;
    t_list *last;

    if (!a || !*a || !(*a)->next)
        return ;
    prev = NULL;
    last = *a;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *a;
    *a = last;
}

void reverse_rotate_b_silent(t_list **b)
{
    t_list *last;
    t_list *prev;

    if (!b || !*b || !(*b)->next)
        return ;
    last = *b;
    prev = NULL;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
}

void reverse_rotate_a_b(t_list **a, t_list **b)
{
    if (!a || !*a || !(*a)->next)
        return ;
    if (!b || !*b || !(*b)->next)
        return ;
    reverse_rotate_a_silent(a);
    reverse_rotate_b_silent(b);
    ft_printf("rrr\n");
}
