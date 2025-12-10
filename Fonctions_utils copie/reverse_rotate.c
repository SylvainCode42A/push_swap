#include "ft_push_swap.h"

void reverse_rotate_a(char **temp_stack_a)
{
    char *temp;
    size_t i;

    i = 0;
    if (!temp_stack_a || !temp_stack_a[0] || !temp_stack_a[1])
        return ;
    while (temp_stack_a[i])
        i++;
    temp = temp_stack_a[i - 1];
    while (i > 1)
    {
        temp_stack_a[i - 1] = temp_stack_a[i - 2];
        i--;
    }
    temp_stack_a[0] = temp;
    printf("rra\n");
}

void reverse_rotate_b(char **temp_stack_b)
{
    char *temp;
    size_t i;

    i = 0;
    if (!temp_stack_b || !temp_stack_b[0] || !temp_stack_b[1])
        return ;
    while (temp_stack_b[i])
        i++;
    temp = temp_stack_b[i - 1];
    while (i > 1)
    {
        temp_stack_b[i - 1] = temp_stack_b[i - 2];
        i--;
    }
    temp_stack_b[0] = temp;
    printf("rrb\n");
}

void reverse_rotate_a_b(char **temp_stack_a, char **temp_stack_b)
{
    size_t i_a;
    size_t i_b;
    char *temp;

    i_a = 0;
    i_b = 0;
    if (temp_stack_a && temp_stack_a[0] && temp_stack_a[1])
    {
        while (temp_stack_a[i_a])
            i_a++;
        temp = temp_stack_a[i_a - 1];
        while (i_a > 1)
        {
            temp_stack_a[i_a - 1] = temp_stack_a[i_a - 2];
            i_a--;
        }
        temp_stack_a[0] = temp;
    }
    if (temp_stack_b && temp_stack_b[0] && temp_stack_b[1])
    {
        while (temp_stack_b[i_b])
            i_b++;
        temp = temp_stack_b[i_b - 1];
        while (i_b > 1)
        {
            temp_stack_b[i_b - 1] = temp_stack_b[i_b - 2];
            i_b--;
        }
        temp_stack_b[0] = temp;
    }
    ft_printf("rrr\n");
}
