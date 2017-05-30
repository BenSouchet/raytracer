/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_opencl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:45:49 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/13 11:49:49 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cf(cl_float *elem1, double elem2)
{
	*elem1 = elem2;
	return (1);
}

int			ci(cl_short *elem1, int elem2)
{
	*elem1 = elem2;
	return (1);
}
