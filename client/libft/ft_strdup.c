/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:01:50 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:59 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "malloc.h"

char		*ft_strdup(const char *s)
{
	char		*dup;

	MALLOC_N(dup, 1 + ft_strlen(s));
	if (!dup)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
