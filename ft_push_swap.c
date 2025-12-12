#include "ft_push_swap.h"

int ft_tablen(char **a)
{
    size_t count;

    count = 0;
    while (a[count])
        count++;
    return (count);
}

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

int secure_args(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("Erreur\n");
        return (0);
    }
    if (argc < 3)
    {
        ft_printf("Mode adaptative\n");
        return (1);
    }
    return (0);
}

t_list *ft_push_swap(int argc, char **argv)
{
    char    **stack_a;
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    stack_a = parsing(argc, argv);
    if (!secure_args)
        return (NULL);
    if (!stack_a)
        return (NULL);
    if (!verify_double(stack_a, ft_tablen(a)))
    {
        ft_printf("There is a duplicate");
        return (NULL);
    }
    a = tab_in_list(stack_a, count, a);
    free_tab(stack_a);
    if (secure_args(argc, argv) == 1)
        a = get_strategie("--adaptative", a);
    else if
        a = get_strategie(argv[3], a);
    return (a);
}
