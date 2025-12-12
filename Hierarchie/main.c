#include "ft_push_swap.h"

int main(int argc, char **argv)
{
    size_t i = 0;
    char **temp;
    if (argc < 2)
    {
        printf("Not arg");
        return 0;
    }
    temp = ft_push_swap(argc, argv);
    while (temp[i] != NULL)
    {
        printf("%s\n", temp[i]);
        free(temp[i]);
        i++;
    }
    free(temp);
    return 0;
}
