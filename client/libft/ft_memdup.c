/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 11:05:17 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:04 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

void		*ft_memdup(void *p, size_t n)
{
	void	*ret;

	MALLOC(ret, n);
	ft_memcpy(ret, p, n);
	return (ret);
}
