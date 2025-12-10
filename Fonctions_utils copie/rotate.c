#include "ft_push_swap.h"

void rotate_a(char **temp_stack_a)
{
    char *temp;
    size_t i;

    i = 0;
    if (!temp_stack_a || !temp_stack_a[0] || !temp_stack_a[1])
        return ;
    temp = temp_stack_a[0];
    while (temp_stack_a[i + 1])
    {
        temp_stack_a[i] = temp_stack_a[i + 1];
        i++;
    }
    temp_stack_a[i] = temp;
    printf("ra\n");
}

void rotate_b(char **temp_stack_b)
{
    char *temp;
    size_t i;

    i = 0;
    if (!temp_stack_b || !temp_stack_b[0] || !temp_stack_b[1])
        return ;
    temp = temp_stack_b[0];
    while (temp_stack_b[i + 1])
    {
        temp_stack_b[i] = temp_stack_b[i + 1];
        i++;
    }
    temp_stack_b[i] = temp;
    printf("rb\n");
}

void rotate_a_b(char **temp_stack_a, char **temp_stack_b)
{
    char *temp;
    size_t i_a;
    size_t i_b;

    i_a = 0;
    i_b = 0;
    
    if (temp_stack_a && temp_stack_a[0] && temp_stack_a[1])
    {
        temp = temp_stack_a[0];
        while (temp_stack_a[i_a + 1])
        {
            temp_stack_a[i_a] = temp_stack_a[i_a + 1];
            i_a++;
        }
        temp_stack_a[i_a] = temp;
    }
    
    if (temp_stack_b && temp_stack_b[0] && temp_stack_b[1])
    {
        temp = temp_stack_b[0];
        while (temp_stack_b[i_b + 1])
        {
            temp_stack_b[i_b] = temp_stack_b[i_b + 1];
            i_b++;
        }
        temp_stack_b[i_b] = temp;
    }
    printf("rr\n");
}
