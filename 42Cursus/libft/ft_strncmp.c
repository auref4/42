#include "libft.h"

int ft_strncmp(const char *first, const char *second, size_t lenght)
{
    size_t  i;

    i = 0;
    if (lenght == 0)
        return (0);
    while (first[i] && second[i] && first[i] == second[i] && i < lenght)
        i++;
    return (first[i] - second[i]);
}