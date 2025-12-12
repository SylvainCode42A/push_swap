#include "ft_push_swap.h"

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
            ft_printf("Erreur\n");
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
