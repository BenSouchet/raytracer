/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_lgt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 09:31:07 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:07 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_interface.h"
#include "rt.h"

#define CPY(a) dest->a = src->a

void
	cpy_lgt
	(t_cl_lgt *dest
	, t_obj *src)
{
	assert(src->type == 'L');
	ft_bzero(dest, sizeof(*dest));
	CPY(pos);
	CPY(rot);
	CPY(clr);
	CPY(intensity);
}
