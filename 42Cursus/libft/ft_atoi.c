#include "libft.h"

int ft_atoi(const char *theString)
{
    int i;
    int signe;
    int nb;

    i = 0;
    nb = 0;
    while ((theString[i] >= '\t' && theString[i] <= '\r') || (theString[i] == ' '))
        i++;
    if (theString[i] == '-' || theString[i] == '+')
    {
        if (theString[i] == '-')
            signe = 1;
        i++;
    }
    while (theString[i] >= '0' && theString[i] <= '9')
    {
        nb = nb * 10 + (theString[i] - 48);
        i++;
    }
    if (signe == 1)
        nb = nb * - 1;
    return (nb);
}