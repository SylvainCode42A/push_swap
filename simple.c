#include "ft_push_swap.h"

void simple_mode(t_ctrl *ctrl)
{
    int a;
    int b;
    int c;

    if (!ctrl || !ctrl->first)
        return ;
    if (!ctrl->first->next)
        return ;
    if (!ctrl->first->next->next)
    {
        a = ctrl->first->data;
        b = ctrl->first->next->data;
        if (a > b)
            swap_a(ctrl);
        return ;
    }
    a = ctrl->first->data;
    b = ctrl->first->next->data;
    c = ctrl->first->next->next->data;
    if (a > b && b > c)
    {
        swap_a(ctrl);
        reverse_rotate_a(ctrl);
    }
    else if (a > c && c > b)
        rotate_a(ctrl);
    else if (b > a && a > c)
        reverse_rotate_a(ctrl);
    else if (b > c && c > a)
    {
        swap_a(ctrl);
        rotate_a(ctrl);
    }
    else if (c > a && a > b)
        swap_a(ctrl);
}
