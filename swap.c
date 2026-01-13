#include "ft_push_swap.h"

void swap_a(t_ctrl *ctrl)
{
    t_list *first;
    t_list *second;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return ;
    first = ctrl->first;
    second = first->next;
    first->next = second->next;
    second->next = first;
    ctrl->first = second;
    if (second == ctrl->last)
        ctrl->last = first;
    ft_printf("sa\n");
    ctrl->count_sa++;
}

int swap_a_silent(t_ctrl *ctrl)
{
    t_list *first;
    t_list *second;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return (0);
    first = ctrl->first;
    second = first->next;
    first->next = second->next;
    second->next = first;
    ctrl->first = second;
    if (second == ctrl->last)
        ctrl->last = first;
    return (1);
}

void swap_b(t_list **b, t_ctrl *ctrl)
{
    t_list *first;
    t_list *second;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    ft_printf("sb\n");
    ctrl->count_rb++;
}

int swap_b_silent(t_list **b)
{
    t_list *first;
    t_list *second;

    if (!b || !*b || !(*b)->next)
        return (0);
    first = *b;
    second = (*b)->next;
    first->next = second->next;
    second->next = first;
    *b = second;
    return (1);
}

void swap_a_b(t_list **b, t_ctrl *ctrl)
{
    int doo;

    if (!ctrl)
        return ;
    doo = 0;
    doo += swap_a_silent(ctrl);
    doo += swap_b_silent(b);
    if (doo == 2)
    {
        ctrl->count_ss++;
        ft_printf("ss\n");
    }
}
