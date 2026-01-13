#include "ft_push_swap.h"

int is_sorted(t_ctrl *ctrl)
{
    t_list *current;

    if (!ctrl || !ctrl->first)
        return (1);
    current = ctrl->first;
    while (current->next)
    {
        if (current->data > current->next->data)
            return (0);
        current = current->next;
    }
    return (1);
}

int size_list_a(t_ctrl *ctrl)
{
    t_list *current;
    int count;

    if (!ctrl)
        return (0);

    current = ctrl->first;
    count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
}

int size_list_b(t_list *b)
{
    int count;

    count = 0;
    while (b)
    {
        count++;
        b = b->next;
    }
    return (count);
}

int size_max_bit(int max)
{
    int bit;

    bit = 0;
    while ((max >> bit) != 0)
        bit++;
    return (bit);
}

int search_max(t_ctrl *ctrl)
{
    t_list *current;
    int max;

    if (!ctrl || !ctrl->first)
        return (0);
    current = ctrl->first;
    max = current->data;
    while (current)
    {
        if (current->data > max)
            max = current->data;
        current = current->next;
    }
    return (max);
}
