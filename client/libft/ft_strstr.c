/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:05:43 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;

	if (!*s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (*s1 && len1 >= len2)
	{
		if (!ft_memcmp(s1, s2, len2))
			return ((char *)s1);
		s1++;
		len1--;
	}
	return (NULL);
}
