#include "libft.h"

char    *ft_strndup(const char *s1, size_t n)
{
        char    *clone;
        size_t  i;

        clone = malloc(sizeof(char) * (n + 1));
        if (!clone)
                return (NULL);
        i = 0;
        while (i < n)
        {
                clone[i] = s1[i];
                i++;
        }
        clone[i] = '\0';
        return (clone);
}