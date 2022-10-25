#include "libft.h"

char    *ft_strchr(const char *string, int searchedChar)
{
    int i;

    i = 0;
    while (string[i] != '\0')
    {
        if (searchedChar == string[i])
            return ((char*)&string[i]);
        i++;
    }
    return (NULL);
}