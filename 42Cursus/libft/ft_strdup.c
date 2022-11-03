#include "libft.h"

static char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *ft_strdup(const char *source)
{
    char    *dest;
    size_t i;

    i = ft_strlen(source);
    dest = malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    ft_strcpy(dest, (char *)source);
    return (dest);
}