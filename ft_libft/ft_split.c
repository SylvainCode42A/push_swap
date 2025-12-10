#include "libft.h"

int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
    char **tab;
    int i;
    int start;
    int j;

    tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!tab)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] == c)
            i++;
        if (!s[i])
            break;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        tab[j++] = substr(s, start, i - start);
    }
    tab[j] = NULL;
    return (tab);
}

int main()
{
    char **tab = ft_split("Salut les amis", ' ');
    return 0;
}
