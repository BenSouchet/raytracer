/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfmt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:52:19 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:42 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFMT_H
# define LIBFMT_H

# include "../libft/libft.h"
# include "../libft/malloc.h"
# include "../libvect/libvect.h"
# include <stdarg.h>

# define ECHO(s, ...)	fmt_print(1, 1, s "\n", sizeof(s), __VA_ARGS__)
# define ERR(s, r, ...)	fmt_print(2, r, s "\n", sizeof(s), __VA_ARGS__)
# define PRINT(s, ...)	fmt_print(1, 1, s, sizeof(s) - 1, __VA_ARGS__)
# define PUT(s)			fmt_print(1, 1, s, sizeof(s) - 1)
# define PUTNL(s)		fmt_print(1, 1, s "\n", sizeof(s))

# define FMT_VECT(v, s, ...) fmt_vect(v, s, sizeof(s) - 1, __VA_ARGS__)

int			fmt_print(int fd, int ret, char *s, size_t n, ...);
void		fmt_fmt(t_vect *a, char *s, size_t n, va_list l);
void		fmt_int(t_vect *a, char **d, size_t *n, va_list l);
void		fmt_int_sign_32(t_vect *a, int base, int x);
void		fmt_int_sign_64(t_vect *a, int base, long x);
void		fmt_int_unsign(t_vect *a, unsigned base, unsigned long x);
void		fmt_vect(t_vect *a, char *s, size_t n, ...);

#endif
