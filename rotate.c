#include "ft_push_swap.h"

void rotate_a(t_ctrl *ctrl)
{
    t_list *first;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return ;
    first = ctrl->first;
    ctrl->first = ctrl->first->next;
    first->next = NULL;
    ctrl->last->next = first;
    ctrl->last = first;
    ft_printf("ra\n");
    ctrl->count_ra++;
}

void rotate_b(t_list **b, t_ctrl *ctrl)
{
    t_list *first;
    t_list *last;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    *b = (*b)->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    ft_printf("rb\n");
    ctrl->count_rb++;
}

int rotate_a_silent(t_ctrl *ctrl)
{
    t_list *first;

    if (!ctrl || !ctrl->first || !ctrl->first->next)
        return (0);
    first = ctrl->first;
    ctrl->first = ctrl->first->next;
    first->next = NULL;
    ctrl->last->next = first;
    ctrl->last = first;
    return (1);
}

int rotate_b_silent(t_list **b)
{
    t_list *first;
    t_list *last;

    if (!b || !*b || !(*b)->next)
        return (0);
    first = *b;
    *b = (*b)->next;
    first->next = NULL;
    last = *b;
    while (last->next)
        last = last->next;
    last->next = first;
    return (1);
}

void rotate_a_b(t_list **b, t_ctrl *ctrl)
{
    int doo = 0;

    if (ctrl && ctrl->first && ctrl->first->next)
        doo += rotate_a_silent(ctrl);
    if (b && *b && (*b)->next)
        doo += rotate_b_silent(b);
    if (doo == 2)
    {
        ctrl->count_rr++;
        ft_printf("rr\n");
    }
}
