/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_req.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 18:40:10 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"
#include "malloc.h"

int			vect_req
	(t_vect *v, size_t size)
{
	size_t	n;

	if (!v->total)
	{
		MALLOC(v->data, size);
		v->total = size;
		v->used = 0;
	}
	if (v->total >= v->used + size)
		return (1);
	if (v->total == 1)
		v->total++;
	n = 1;
	while (v->total * n * GROWTH_FACTOR < v->used + size)
		n++;
	return (vect_grow(v, size));
}
