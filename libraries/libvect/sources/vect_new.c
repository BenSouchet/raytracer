/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:52:14 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"
#include "malloc.h"

t_vect		*vect_new(void *data, size_t size)
{
	t_vect	*ret;

	MALLOC1(ret);
	vect_init(ret);
	vect_add(ret, data, size);
	return (ret);
}
