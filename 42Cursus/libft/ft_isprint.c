int ft_isprint(int character)
{
    if (character >= 32 && character <= 126)
        return (1);
    else
        return (0);
}