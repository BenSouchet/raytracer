/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:00:20 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:53:42 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

#define INC(x)	d += x; s += x;

static void	memcpy_carry(unsigned char *d, unsigned char *s, size_t n)
{
	if (n & 16)
	{
		*(unsigned long *)(d + 0) = *(unsigned long *)(s + 0);
		*(unsigned long *)(d + 8) = *(unsigned long *)(s + 8);
		INC(16);
	}
	if (n & 8)
	{
		*(unsigned long *)d = *(unsigned long *)s;
		INC(8);
	}
	if (n & 4)
	{
		*(unsigned int *)d = *(unsigned int *)s;
		INC(4);
	}
	if (n & 2)
	{
		*(unsigned short *)d = *(unsigned short *)s;
		INC(2);
	}
	if (n & 1)
		*d = *s;
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n && (uintptr_t)d % 8)
	{
		*d++ = *s++;
		n--;
	}
	while (n >= 32)
	{
		*(unsigned long *)(d + 0) = *(unsigned long *)(s + 0);
		*(unsigned long *)(d + 8) = *(unsigned long *)(s + 8);
		*(unsigned long *)(d + 16) = *(unsigned long *)(s + 16);
		*(unsigned long *)(d + 24) = *(unsigned long *)(s + 24);
		INC(32);
		n -= 32;
	}
	memcpy_carry(d, s, n);
	return (dest);
}
