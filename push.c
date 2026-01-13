#include "ft_push_swap.h"

void push_a_to_b(t_list **b, t_ctrl *ctrl)
{
    t_list *temp;

    if (!ctrl || !ctrl->first)
        return ;
    temp = ctrl->first;
    ctrl->first = ctrl->first->next;
    if (!ctrl->first)
        ctrl->last = NULL;
    temp->next = *b;
    *b = temp;
    ft_printf("pb\n");
    ctrl->count_pb++;
}

void push_b_to_a(t_list **b, t_ctrl *ctrl)
{
    t_list *temp;

    if (!ctrl || !b || !*b)
        return ;
    temp = *b;
    *b = (*b)->next;
    temp->next = ctrl->first;
    ctrl->first = temp;
    if (!ctrl->last)
        ctrl->last = temp;
    ft_printf("pa\n");
    ctrl->count_pa++;
}
