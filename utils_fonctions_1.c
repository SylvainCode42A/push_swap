#include "ft_push_swap.h"

char	*strjoin_space(char const *s1, char const *s2, int space)
{
    char *dest;
    size_t total;
    size_t len_1;
    size_t len_2;
    size_t count;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    len_1 = ft_strlen(s1);
    len_2 = ft_strlen(s2);
    total = len_1 + len_2;
    count = 1;
    if (space)
        count += 1;
    dest = malloc(total + count);
    if (!dest)
        return NULL;
    memcpy(dest, s1, len_1);
    memcpy(dest + len_1, s2, len_2);
    if (space)
        dest[len_1 + len_2] = ' ';
    dest[len_1 + len_2 + 1] = '\0';
    return (dest);
}

void	ft_putfloat(float nb)
{
    int nb_int;
    int nb_dec;

    if (nb < 0)
        write(2, "-", 1);
    nb = nb * 100;
    nb_int = (int)nb;
    nb_dec = (int)((nb - nb_int) * 100);
    ft_putnbr(nb_int);
    write(2, ".", 1);
    if (nb_dec < 10)
        write(2, "0", 1);
    ft_putnbr(nb_dec);
    write(2, "%", 1);
}
