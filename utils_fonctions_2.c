#include "ft_push_swap.h"

void free_tab(char **a)
{
    size_t i;

    i = 0;
    while (a[i])
    {
        free(a[i]);
        i++;
    }
    free(a);
}

void free_list(t_list **a, t_list **b)
{
    t_list *temp;

    while (a && *a)
    {
        temp = (*a)->next;
        free(*a);
        *a = temp;
    }
    while (b && *b)
    {
        temp = (*b)->next;
        free(*b);
        *b = temp;
    }
}

void print_list(t_list *a)
{
    while (a)
    {
        ft_printf("%d\n", (int)a->data);
        a = a->next;
    }
}
