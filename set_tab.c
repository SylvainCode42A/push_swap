#include "ft_push_swap.h"

int verify_double(char **a, int size)
{
    size_t i;
    size_t j;

    i = 0;
    j = i + 1;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (ft_strcmp(a[i], a[j]) == 0)
            {
                ft_printf("Erreur\n");
                return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int verify_args(char *s)
{
    size_t i;

    i = 0;
    if (!s || s[0] == '\0')
        return(0);
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
        if (s[i] == '+' || s[i] == '-')
            return (0);
        if (s[i] == '\0')
            return (0);
    }
    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

char **parsing(int argc, char **argv)
{
    size_t i;
    char **normalized;
    char *tmp;
    char *tempnormalized;
    

    tempnormalized = ft_strdup("");
    if (!tempnormalized)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        if (!verify_args(argv[i]))
        {
            free(tempnormalized);
            return (NULL);
        }
        tmp = strjoin_space(tempnormalized, argv[i], i < argc - 1);
        free(tempnormalized);
        if (!tmp)
            return (NULL);
        tempnormalized = tmp;
        i++;
    }
    normalized = ft_split(tempnormalized, ' ');
    free(tempnormalized);
    return (normalized);
}
