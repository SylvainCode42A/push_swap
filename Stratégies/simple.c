#include "ft_push_swap.h"

int simple_mode(char **a, int size)
{
    size_t  i;
    size_t  j;
    char    *temp;

    i = 0;
    j = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_atoi(a[0]) > ft_atoi(a[1]))
                swap_a(a)
            rotate_a(a);
            if (j == 4)
            {
                j = 0;
                while (j < 4)
                {
                    reverse_rotate_a(a);
                    j++;
                }
                j = 0;
            }
            j++;
        }
        i++;
    }
    print_elem(a);
    free_tab(a);
    return (0);
}
