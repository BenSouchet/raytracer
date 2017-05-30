/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:24:20 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

int
	vect_memcmp
	(t_vect *a
	, unsigned char *s
	, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	i = 0;
	s1 = a->data;
	while (*s1 == *s
		&& (void *)s1 < a->data + a->used
		&& *s
		&& n)
	{
		s1++;
		s++;
		n++;
	}
	return (*s - *s1);
}
