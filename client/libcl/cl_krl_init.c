/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:54:21 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:09 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/malloc.h"
#include "libcl.h"

void
	cl_krl_init
	(t_cl_krl *krl
	, size_t nargs)
{
	MALLOC_N(krl->args, nargs);
	MALLOC_N(krl->sizes, nargs);
	krl->nargs = nargs;
}
