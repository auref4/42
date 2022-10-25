int ft_atoi(char *str)
{
    int i;
    int signe;
    int nb;

    i = 0;
    nb = 0;
    while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signe = 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    if (signe == 1)
        nb = nb * - 1;
    return (nb);
}