#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <stdlib.h>

int ft_atoi(const char *theString);
int ft_isalnum(int character);
int ft_isalpha(int character);
int ft_isascii(int character);
int ft_isdigit(int character);
int ft_isprint(int character);
char    *ft_strchr(const char *string, int searchedChar);
char    *ft_strrchr(const char *string, int searchedChar);
size_t  ft_strlen(const char *theString);
int ft_tolower(int character);
int ft_toupper(int character);
char    *ft_strdup(const char *source);
int ft_strncmp(const char *first, const char *second, size_t lenght)

#endif