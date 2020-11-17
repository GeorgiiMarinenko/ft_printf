/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:51:43 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/06 16:14:09 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				*ft_memset(void *dest, int c, size_t b_size);
void				ft_bzero(void *dist, size_t count);
void				*ft_memcpy(void *dest, const void *srcs, size_t b_size);
void				*ft_memccpy (void *dest, const void *srcs,
					int c, size_t b_size);
void				*ft_memmove(void *dst, const void *src, size_t b_size);
void				*ft_memchr (const void *arr, int c, size_t b_size);
int					ft_memcmp(const void *arr1, const void *arr2,
					size_t b_size);
size_t				ft_strlen (const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t b_size);
size_t				ft_strlcat(char *dst, const char *src, size_t b_size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int					ft_strncmp(char *s1, char *s2, unsigned int n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t	num, size_t	b_size);
char				*ft_strdup(char *src);

void				ft_putchar_fd(char symb, int fd);
void				ft_putstr_fd(const char *str, const int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl_fd(char const *str, int fd);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
void				(*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
