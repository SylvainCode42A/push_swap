#include "ft_push_swap.h"

void radix_sort(t_ctrl *ctrl, t_list **b, int i)
{
    int count = size_list_a(ctrl);

    while (count > 0)
    {
        if (((ctrl->first->data >> i) & 1) == 1)
            rotate_a(ctrl);
        else
            push_a_to_b(b, ctrl);
        count--;
    }
}

void complex_mode(t_ctrl *ctrl, t_list **b)
{
    int max_bit = size_max_bit(search_max(ctrl));
    int i;

    i = 0;
    while (i < max_bit)
    {
        radix_sort(ctrl, b, i);
        while (*b)
            push_b_to_a(b, ctrl);
        i++;
    }
}
