/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 19:51:06 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 20:13:54 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*get_shader_name(t_obj *obj)
{
	if (obj->shader < 1)
		return (ft_strf("NO"));
	else if (obj->shader < 3)
		return (ft_strf("STAR"));
	else if (obj->shader < 5)
		return (ft_strf("WOOD"));
	else if (obj->shader < 7)
		return (ft_strf("MARBLE 1"));
	else if (obj->shader < 9)
		return (ft_strf("MARBLE 2"));
	else if (obj->shader < 11)
		return (ft_strf("MARBLE 3"));
	else if (obj->shader < 13)
		return (ft_strf("MARBLE 4"));
	else if (obj->shader < 15)
		return (ft_strf("MARBLE 5"));
	else if (obj->shader < 17)
		return (ft_strf("MARBLE 6"));
	else if (obj->shader < 19)
		return (ft_strf("MARBLE 7"));
	else if (obj->shader < 21)
		return (ft_strf("SKY STAR"));
	else if (obj->shader < 23)
		return (ft_strf("SKY DAY"));
	return (ft_strf("   "));
}
