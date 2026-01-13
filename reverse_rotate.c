#include "ft_push_swap.h"

void reverse_rotate_a(t_ctrl *ctrl)
{
    t_list *prev;
    t_list *last;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return;

    prev = NULL;
    last = ctrl->first;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = ctrl->first;
    ctrl->first = last;
    ctrl->last = prev;

    ft_printf("rra\n");
    ctrl->count_rra++;
}

void reverse_rotate_b(t_list **b, t_ctrl *ctrl)
{
    t_list *prev;
    t_list *last;

    if (!b || !*b || !(*b)->next)
        return;

    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = *b;
    *b = last;

    ft_printf("rrb\n");
    ctrl->count_rrb++;
}

int reverse_rotate_a_silent(t_ctrl *ctrl)
{
    t_list *prev;
    t_list *last;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return (0);
    prev = NULL;
    last = ctrl->first;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = ctrl->first;
    ctrl->first = last;
    ctrl->last = prev;
    return (1);
}

int reverse_rotate_b_silent(t_list **b)
{
    t_list *prev;
    t_list *last;

    if (!b || !*b || !(*b)->next)
        return (0);
    prev = NULL;
    last = *b;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *b;
    *b = last;
    return (1);
}

void reverse_rotate_a_b(t_list **b, t_ctrl *ctrl)
{
    int doo = 0;

    doo += reverse_rotate_a_silent(ctrl);
    doo += reverse_rotate_b_silent(b);
    if (doo == 2)
    {
        ctrl->count_rrr++;
        ft_printf("rrr\n");
    }
}
