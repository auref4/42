#include <stddef.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strrchr(const char *string, int searchedChar)
{
    int i;

    i = ft_strlen((char *)string);
    i--;
    while (i >= 0)
    {
        if (searchedChar == string[i])
            return ((char *)&string[i]);
        i--;
    }
    return (NULL);
}