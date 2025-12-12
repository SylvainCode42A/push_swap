#include "ft_push_swap.h"

int cmp(long a, long b)
{
    if (a < b)
        return (-1);
    else if (a > b)
        return (1);
    else
        return (0);
}

int is_sorted(t_list *a, int (*cmp)(long, long))
{
    while (a && (a)->next)
    {
        if (cmp(a->data, a->next->data) > 0)
            return (0);
        a = a->next;
    }
    return (1);
}

void ft_list_sort(t_list **a, int (*cmp)(long, long))
{
    if (!*a || !a)
        return ;
    while (!is_sorted(a))
    {
        if ((*a)->next && cmp(*a->data, (*a)->next->data) > 0)
            swap(a);
        rotate_a(a);
    }
}
