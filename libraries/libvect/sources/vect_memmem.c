/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_memmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:50:30 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

void	*vect_memmem(t_vect *a, unsigned char *s, size_t n)
{
	size_t				i;
	unsigned char		*s1;

	s1 = a->data;
	while ((void *)s1 + n < a->data + a->used)
	{
		i = 0;
		while (i < n && s1[i] == s[i])
			i++;
		if (i == n)
			return (s1);
		s1++;
		s++;
	}
	return (NULL);
}
