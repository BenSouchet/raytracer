/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_fmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 02:51:31 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:53:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

static void
	fmt
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	t_vect	*v;

	if (**d == '-' || ft_isdigit(**d))
		return (fmt_int(a, d, n, l));
	else if (**d == 'a')
		fmt_int_sign_32(a, 10, va_arg(l, t_i32));
	else if (**d == 'b')
		fmt_int_sign_64(a, 10, va_arg(l, t_i64));
	else if (**d == 'c' || **d == 'd')
		fmt_int_unsign(a, 10, va_arg(l, t_u64));
	else if (**d == '%')
		VECT_STRADD(a, "%");
	if (**d == 's')
		vect_str_add(a, va_arg(l, char *));
	else if (**d == 'v')
	{
		v = va_arg(l, t_vect *);
		vect_add(a, v->data, v->used);
	}
	(*d)++;
	(*n)--;
}

static void
	fmt_arr
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	size_t	arr_len;
	void	*arr;

	arr_len = va_arg(l, size_t);
	arr = va_arg(l, void *);
	VECT_STRADD(a, "{");
	while (arr_len)
	{
		if (**d == 'a')
		{
			fmt_int_sign_32(a, 10, *(t_i32 *)arr);
			arr += sizeof(t_i32);
		}
		arr_len--;
		if (arr_len)
			VECT_STRADD(a, ", ");
	}
	VECT_STRADD(a, "}");
	(*d)++;
	(*n)--;
}

void
	fmt_fmt
	(t_vect *a
	, char *s
	, size_t n
	, va_list l)
{
	char	*d;

	if (!((d = ft_memchr(s, '%', n))
		|| (d = ft_memchr(s, '*', n))))
	{
		vect_add(a, s, n);
		return ;
	}
	vect_add(a, s, d - s);
	n -= d - s;
	d++;
	n--;
	if (*(d - 1) == '%')
		fmt(a, &d, &n, l);
	else if (*(d - 1) == '*')
		fmt_arr(a, &d, &n, l);
	fmt_fmt(a, d, n, l);
}
