/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:37:28 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	unsigned char		*tmp2;

	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (dst > src)
	{
		tmp = tmp + n;
		tmp2 = tmp2 + n;
		while (n--)
			*--tmp = *--tmp2;
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
