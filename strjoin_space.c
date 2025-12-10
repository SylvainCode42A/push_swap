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
    len_1 = strlen(s1);
    len_2 = strlen(s2);
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
