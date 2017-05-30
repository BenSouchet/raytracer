/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 18:28:07 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <string.h>

# define COMPARE(a, b)	(((a) > (b)) - ((a) < (b)))
# define MIN(a,b)	((a <= b) ? a : b)
# define MAX(a,b)	((a >= b) ? a : b)
# define LEN(x)		(sizeof(x) / sizeof(x[0]))
# define NEG(x)		((x < 0) ? 1 : 0)
# define SIGN(x)	((x < 0) ? - 1 : 1)
# define ABS(x)		(((x) < 0) ? (-x) : (x))

# define BZERO(a)		ft_bzero(&a, sizeof(a))
# define MEMCPY(a, b)	ft_memcpy(&a, (b), sizeof(a))
# define MEMCHR(a, b)	ft_memchr((a), (b), sizeof(a) - 1)
# define STRONLY(s, x)	ft_only(s, ft_strlen(s), x, sizeof(x) - 1)
# define STRSPLIT(s, x)	ft_nsplit(s, ft_strlen(s), x, sizeof(x) - 1)
# define VONLY(v, x)	ft_only(v.data, v.used, x, sizeof(x) - 1)
# define VSPLIT(v, x)	ft_nsplit((v).data, (v).used, x, sizeof(x) - 1)

# define WHITESPACE	" \t\n\v\f\r"
# define DIGIT		"0123456789"

# define STREND(s)	ft_memchr(s, '\0', -1)

# define STRTOB2(s, x)	ft_atoi(s, (unsigned  long *)&x, 2, 0)
# define STRTOB3(s, x)	ft_atoi(s, (unsigned long *)&x, 3, 0)
# define STRTOB10(s, x)	ft_atoi(s, (unsigned long *)&x, 10, 0)

typedef struct		s_list
{
	void			*p;
	struct s_list	*next;
}					t_list;

typedef int			(*t_cmp_f) (void *, void *);

char				*ft_atoi(char *s, unsigned long *n, int base, int ucase);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_bytecmp(const void *p, unsigned char c, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_only(void *p1, size_t n1, void *p2, size_t n2);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_tolower(int i);
int					ft_toupper(int i);
size_t				ft_strlen(const char *s);
unsigned char		**ft_nsplit(void *s, size_t n1, void *match, size_t n2);
unsigned char		*ft_word(void **p, size_t *n1, void *match, size_t n2);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memdup(void *p, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_iqsort(int *t, size_t n, bool rev);
void				ft_qsort(void **t, size_t n, t_cmp_f cmp, int rev);

#endif
