/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:30:39 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:53:15 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOW (ucase ? 'A' : 'a')

#include "libft.h"

char
	*fmt_atoi
	(char *s
	, unsigned long *n
	, int base
	, int ucase)
{
	while ((((*s >= '0' && *s < '0' + MIN(base, 10)))
		&& (base <= 10 || ((*s >= LOW && *s < LOW + base - 9)))))
	{
		*n = (*n * base) + (*s - (ft_isdigit(*s) ? '0' : LOW - 10));
		s++;
	}
	return (s);
}
