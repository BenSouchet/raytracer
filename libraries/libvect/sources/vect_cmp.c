/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_cmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:11:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

int		vect_cmp(t_vect *a, t_vect *b)
{
	unsigned char	*as;
	unsigned char	*bs;

	as = a->data;
	bs = b->data;
	while ((void *)as < a->data + a->used
		&& (void *)bs < b->data + b->used
		&& *as == *bs)
	{
		as++;
		bs++;
	}
	return (as - bs);
}
