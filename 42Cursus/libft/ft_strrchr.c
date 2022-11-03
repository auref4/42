#include "libft.h"

char    *ft_strrchr(const char *string, int searchedChar)
{
    int i;

    i = ft_strlen(string);
    i--;
    while (i >= 0)
    {
        if (searchedChar == string[i])
            return ((char *)&string[i]);
        i--;
    }
    return (NULL);
}