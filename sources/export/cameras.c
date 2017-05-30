/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:05:36 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/16 22:05:50 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		export_camera(t_obj *cam, int fd)
{
	write(fd, "<camera>\n", 9);
	write(fd, "\t<name>", 7);
	write(fd, (char *)cam->n, ft_strlen((char *)cam->n));
	write(fd, "</name>\n", 8);
	write(fd, "\t<position>", 11);
	ft_putfloat_fd((float)cam->pos.x, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)cam->pos.y, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)cam->pos.z, fd);
	write(fd, "</position>\n", 12);
	write(fd, "\t<rotation>", 11);
	ft_putfloat_fd((float)cam->rot.x, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)cam->rot.y, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)cam->rot.z, fd);
	write(fd, "</rotation>\n", 12);
	write(fd, "\t<focal>", 8);
	ft_putshort_fd((short)cam->focal, fd);
	write(fd, "</focal>\n", 9);
	write(fd, "</camera>\n\n", 11);
}
