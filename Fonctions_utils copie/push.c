#include "ft_push_swap.h"

void push_a_to_b(char **a, char **b)
{
    size_t i;

    if (!a[0])
        return ;
    i = 0;
    while (b[i])
        i++;
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }
    b[0] = a[0];
    i = 0;
    while (a[i + 1])
    {
        a[i] = a[i + 1];
        i++;
    }
    a[i] = NULL;
    ft_printf("pb\n");
}

void push_b_to_a(char **a, char **b)
{
    size_t i;

    if (!b[0])
        return ;
    i = 0;
    while (a[i])
        i++;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[0] = b[0];
    i = 0;
    while (b[i + 1])
    {
        b[i] = b[i + 1];
        i++;
    }
    b[i] = NULL;
    ft_printf("pa\n");
}
