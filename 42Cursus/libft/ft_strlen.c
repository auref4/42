#include <stddef.h>

size_t  ft_strlen(const char *theString)
{
    size_t i;

    i = 0;
    while (theString[i] != '\0')
        i++;
    return (i);
}