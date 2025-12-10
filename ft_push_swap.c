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

void print_elem(char **a)
{
    size_t i;

    i = 0;
    while (a[i])
    {
        ft_printf("%s\n", a[i]);
        i++;
    }
}

int get_mode(int argc, char **argv)
{
    int count;

    count = 0;
    if (argc > 3)
        return (1);
    if (argv[1] == "--simple")
    {
        while (stack_a[count])
            count++;
        simple_mode(a, count);
    }
    if (argv[1] == "--medium")


    if (argv[1] == "--complex")


    if (argv[1] == "--adaptative")

    return (0);
}

char **ft_push_swap(int argc, char **argv)
{
    char **stack_a;
    char **stack_b;
    int count;

    stack_a = parsing(argc, argv);
    if (!stack_a)
        return (NULL);
    count = 0;
    while (stack_a[count])
        count++;
    if (!verify_double(stack_a, count))
    {
        ft_printf("There is a duplicate");
        return (NULL);
    }
    return (stack_a);
}
