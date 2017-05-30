/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_wrap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 20:51:02 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:54:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"
#include "libft.h"
#include "malloc.h"

t_vect			*vect_wrap
	(void *data, size_t size)
{
	t_vect		*ret;

	MALLOC1_ZERO(ret);
	ret->total = size;
	ret->used = size;
	ret->data = data;
	return (ret);
}
