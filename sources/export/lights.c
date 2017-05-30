/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:06:23 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:26:43 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	export_light_part2(t_obj *light, int fd)
{
	write(fd, "\t<position>", 11);
	ft_putfloat_fd((float)light->pos.x, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)light->pos.y, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)light->pos.z, fd);
	write(fd, "</position>\n", 12);
	write(fd, "\t<color-rgb>", 12);
	ft_putfloat_fd((float)light->clr.x * 255., fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)light->clr.y * 255., fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)light->clr.z * 255., fd);
	write(fd, "</color-rgb>\n", 13);
	write(fd, "\t<intensity>", 12);
	ft_putfloat_fd((float)light->intensity, fd);
	write(fd, "</intensity>\n", 13);
	write(fd, "</light>\n\n", 10);
}

void		export_light(t_obj *light, int fd)
{
	write(fd, "<light>\n", 8);
	write(fd, "\t<name>", 7);
	write(fd, (char *)light->n, ft_strlen((char *)light->n));
	write(fd, "</name>\n", 8);
	write(fd, "\t<type>", 7);
	if (light->forme == T_DIFFUSE)
		write(fd, "Diffuse", 7);
	else if (light->forme == T_DIRECTIONAL)
		write(fd, "Directionnal", 12);
	else
		write(fd, "Spot", 4);
	write(fd, "</type>\n", 8);
	write(fd, "\t<visibility>", 13);
	(light->visibility == 1) ? write(fd, "True", 4) : write(fd, "False", 5);
	write(fd, "</visibility>\n", 14);
	write(fd, "\t<flare-visibility>", 19);
	write(fd, "False", 5);
	write(fd, "</flare-visibility>\n", 20);
	export_light_part2(light, fd);
}
