/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgarkbit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:48:38 by tgarkbit          #+#    #+#             */
/*   Updated: 2019/11/20 09:16:52 by tgarkbit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# define BUFF_SIZE 4
# define MINUS form.flag[0]
# define PLUS form.flag[1]
# define ZERO form.flag[2]
# define HASHTAG form.flag[3]
# define SPACE form.flag[4]
# define H 1
# define HH 2
# define L 3
# define LL 4

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_format
{
	int				*flag;
	int				width;
	int				precision;
}					t_format;

int					ft_atoi(const char *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *source,
		int ch, size_t count);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *buf1, const void *buf2, size_t count);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *destptr, const char *srcptr);
char				*ft_strncpy(char *destptr, const char *srcptr, size_t num);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strncat(char *str1, const char *str2, size_t count);
size_t				ft_strlcat(char *dst, const char *src, size_t count);
char				*ft_strchr(const char *string, int symbol);
char				*ft_strrchr(const char *string, int symbol);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str,
			const char *to_find, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoidie(const char *str);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
void				ft_free_ar(int n, char **ar);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strcatspace(char *str1, const char *str2);
void				ft_swapint(int *a, int *b);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list
			*elem));

int					ft_max(int a, int b);
int					get_next_line(const int fd, char **line);
long	double		ft_pow(long double num, int power);
void				ft_putupstr(char *s);
void				ft_putnstr(char *str, size_t n);
void				ft_die(char *str);
int					*ft_intmalloc(int len);
char				*ft_strjoinfree(char const *s1, char const *s2);
int					ft_atoi(const char *str);
void				ft_putnbrpos(long long int nb);
void				ft_putunsignednbrpos(unsigned long long nb);
void				ft_write(char *s, int len);
void				ft_putnstr(char *str, size_t n);
void				ft_memswap(char *s1, char *s2);
char				*ft_itoabaseunsigned(unsigned long long num,
		char *str, int base);
void				reverse(char str[], int length);
void				ft_putupstr(char *s);

int					ft_printf(char *format, ...);
int					ft_format(char *ss, va_list ap);
int					ft_len_to_type(char *s);
int					ft_parse_name(char *s);
int					*ft_parse_flag(int num, char *ss);
int					ft_parse_width(char *ss);
int					ft_parse_precision(char *ss);
int					ft_parse_size(char *ss);
int					ft_checkzero(char *ss);
void				ft_int(char *ss, va_list ap);
void				ft_flagint(long long num, char *ss);
int					ft_intlen(long long int num);
void				ft_intleft(long long num, t_format form);
void				ft_intright(long long num, t_format form);
void				ft_octet(char *ss, va_list ap);
void				ft_ptet(char *ss, va_list ap);
void				ft_unsignedint(char *ss, va_list ap);
void				ft_flagunsignedint(unsigned long long num, char *ss);
void				ft_unsignedintright(unsigned long long num, t_format form);
void				ft_unsignedintleft(unsigned long long num, t_format form);
int					ft_unsignedintlen(unsigned long long int num);
void				ft_flagstr(char *str, char *ss);
void				ft_flagpercent(char *ss);
void				ft_flagchar(char *ss, char c);
void				ft_xtetleft(char *str, t_format form, int mode);
void				ft_xtetright(char *str, t_format form, int mode);
void				ft_flagxtet(unsigned long long num, char *ss, int mode);
void				ft_xtet(char *ss, va_list ap, int mode);
void				ft_costylleft(t_format form);
void				ft_costylright(t_format form);
void				ft_double(char *ss, long double num);
char				*ft_k3(long double *num, t_format form);
double				ft_okrug(int i);
void				ft_putfloatright(char *ss, char *num, t_format form);
void				ft_k2(t_format form, char *num, char *ss);
void				ft_putfloatleft(char *ss, char *num, t_format form);
void				ft_float(char *ss, va_list ap);
#endif
