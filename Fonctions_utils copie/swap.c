#include "ft_push_swap.h"

char **swap_a(char **temp_stack_a)
{
    char *temp;

    if (!temp_stack_a || !temp_stack_a[0] || !temp_stack_a[1])
        return (temp_stack_a);
    temp = temp_stack_a[0];
    temp_stack_a[0] = temp_stack_a[1];
    temp_stack_a[1] = temp;
    ft_printf("sa\n");
    return (temp_stack_a);
}

char **swap_b(char **temp_stack_b)
{
    char *temp;

    if (!temp_stack_b || !temp_stack_b[0] || !temp_stack_b[1])
        return (temp_stack_b);
    temp = temp_stack_b[0];
    temp_stack_b[0] = temp_stack_b[1];
    temp_stack_b[1] = temp;
    ft_printf("sb\n");
    return (temp_stack_b);
}


void swap_a_b(char **temp_stack_a, char **temp_stack_b)
{
    char *temp;

    if (temp_stack_a && temp_stack_a[0] && temp_stack_a[1])
    {
        temp = temp_stack_a[0];
        temp_stack_a[0] = temp_stack_a[1];
        temp_stack_a[1] = temp;
    }
    if (temp_stack_b && temp_stack_b[0] && temp_stack_b[1])
    {
        temp = temp_stack_b[0];
        temp_stack_b[0] = temp_stack_b[1];
        temp_stack_b[1] = temp;
    }
    ft_printf("ss\n");
}
