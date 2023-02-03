#include <unistd.h>

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int    ft_size(char *str)
{
    int    i;

    i = 0;
    while (str[i] == 32 || str[i] == 9)
        i++;
    while (str[i] != 32 && str[i] != 9)
        i++;
    return (i);
}

void    ft_rev_wstr(char *str)
{
    int    i;
    int size_first_word;

    size_first_word = ft_size(str);
    i = ft_strlen(str) - 1;
    while (str[i] == 32 || str[i] == 9)
        i--;
    while (str[i] && str[i] != 32 && str[i] != 9)
        i--;
    i = i + 1;
    while (str[i] && (str[i] != 32 && str[i] != 9))
    {
        write(1, &str[i], 1);
        i++;
    }
    i--;
    while (i >= size_first_word && str[i])
    {
        while (str[i] != 32 && str[i] != 9)
        {
            if (i == 0)
                break;
            i--;
        }
        if (str[i] == 32 || str[i] == 9)
        {
            write(1, &str[i], 1);
            i--;
        }
        while (str[i] && (str[i] == 32 || str[i] == 9))
            i--;
        while (str[i] && (str[i] != 32 && str[i] != 9))
            i--;
        i++;
        while (str[i] && (str[i] != 32 && str[i] != 9))
        {
            write(1, &str[i], 1);
            i++;
        }
        i--;
    }
}

int    main(int ac, char **av)
{
    if (ac == 2)
        ft_rev_wstr(av[1]);
    write(1, "\n", 1);
}
