/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molapoug <molapoug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:13:35 by molapoug          #+#    #+#             */
/*   Updated: 2025/05/30 19:19:35 by molapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* include for libft */
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

/* strcut */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ################################# */
/* fonctions with int prototypes */
/* ################################# */
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_lstsize(t_list *lst);

/* fonctions with char prototypes */
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strncpy(char *dest, char *src, int n);
char				*ft_strncat(char *dest, char *src, int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_itoa(int n);
char				*ft_strdup(char *s);

/* fonction with void protoypes */
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t size);
void				*ft_memset(void *s, int ch, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_putnbr_fd(int nbr, int fd);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_putchar(char c);
void				ft_putstr(char *str);

/* fonctions with size_t prototypes */
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
/* fonctions with t_size prototypes */
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
