/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:43:06 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:49:49 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_qsort
	(void **t, size_t n, t_cmp_f cmp, int rev)
{
	int		i;
	int		j;
	void	*p;
	void	*tmp;

	if (n < 2)
		return ;
	p = t[n / 2];
	i = 0;
	j = n - 1;
	while (42)
	{
		while ((rev ? cmp(t[i], p) : cmp(p, t[i])) > 0)
			i++;
		while ((rev ? cmp(p, t[j]) : cmp(t[j], p)) > 0)
			j--;
		if (i >= j)
			break ;
		tmp = t[i];
		t[i] = t[j];
		t[j--] = tmp;
		i++;
	}
	ft_qsort(t, i, cmp, rev);
	ft_qsort(t + i, n - i, cmp, rev);
}
