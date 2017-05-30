/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:19:47 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 15:48:47 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Function to delete spaces, tabs & comments of lines from get_next_line
*/

char		*clear_line(t_parser *p, char *str, int pos, int n)
{
	char	*new;

	while (str[pos] && (str[pos] == ' ' || str[pos] == '\t'))
		pos++;
	if ((!str[pos] || (str[pos] == '/' && str[pos + 1] == '/')) &&
	ft_free(str))
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[pos] && !ft_strcmp(str, "//", pos))
	{
		if (ft_strcmp(str, "<!--", pos) && !(p->copy = 0))
			pos += 4;
		if (ft_strcmp(str, "-->", pos) && (p->copy = 1))
			pos += 3;
		if (p->copy == 1)
			new[++n] = str[pos];
		++pos;
	}
	new[n + 1] = 0;
	free(str);
	return (new);
}
