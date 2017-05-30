/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:32:03 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:17 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_word(void **p, size_t *n1, void *match, size_t n2)
{
	unsigned char	*r;
	unsigned char	**s;

	s = (unsigned char **)p;
	while (*n1 && ft_memchr(match, (int)**s, n2))
	{
		(*n1)--;
		(*s)++;
	}
	r = *s;
	while (*n1 && !ft_memchr(match, (int)**s, n2))
	{
		(*n1)--;
		(*s)++;
	}
	return (r == *s ? NULL : r);
}
