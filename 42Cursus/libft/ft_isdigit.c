#include "libft.h"

int ft_isdigit(int character)
{
    if (character >= '0' && character <= '9')
        return (1);
    else
        return(0);
}