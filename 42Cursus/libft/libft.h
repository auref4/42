#ifndef LIBFT_H
#define LIBFT_H

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

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
int ft_strncmp(const char *first, const char *second, size_t lenght);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_striteri(char *s, void (*f)(unsigned int, char*));

#endif
