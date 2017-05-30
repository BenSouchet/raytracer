/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:06:56 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/12 19:30:40 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			export_shape_object(short shape, int fd)
{
	if (shape == T_SPHERE)
		return (write(fd, "Sphere", 6));
	else if (shape == T_CUBE)
		return (write(fd, "Cube", 4));
	else if (shape == T_CYLINDER)
		return (write(fd, "Cylinder", 8));
	else if (shape == T_PLANE)
		return (write(fd, "Plane", 5));
	else if (shape == T_CONE)
		return (write(fd, "Cone", 4));
	else if (shape == T_TORUS)
		return (write(fd, "Torus", 5));
	else if (shape == T_PYRAMID)
		return (write(fd, "Pyramid", 7));
	else if (shape == T_TETRAHEDRON)
		return (write(fd, "Tetrahedron", 11));
	else if (shape == T_OCTAHEDRON)
		return (write(fd, "Octahedron", 10));
	else if (shape == T_MOEBIUS)
		return (write(fd, "Moebius", 7));
	return (write(fd, "Object", 6));
}

static void	export_object_dimensions(t_obj *obj, int fd)
{
	write(fd, "\t<width>", 8);
	ft_putfloat_fd((float)obj->width, fd);
	write(fd, "</width>\n", 9);
	write(fd, "\t<height>", 9);
	ft_putfloat_fd((float)obj->height, fd);
	write(fd, "</height>\n", 10);
	write(fd, "\t<lenght>", 9);
	ft_putfloat_fd((float)obj->lenght, fd);
	write(fd, "</lenght>\n", 10);
}

static void	export_object_part3(t_obj *obj, int fd)
{
	write(fd, "\t<reflection>", 13);
	ft_putfloat_fd((float)obj->reflex, fd);
	write(fd, "</reflection>\n", 14);
	write(fd, "\t<refraction>", 13);
	ft_putint_fd((int)obj->refrac, fd);
	write(fd, "</refraction>\n", 14);
	write(fd, "\t<specular>", 11);
	ft_putint_fd((int)obj->specular, fd);
	write(fd, "</specular>\n", 12);
	write(fd, "\t<shader>", 9);
	obj->shader += (obj->shader & 1) ? 1 : 0;
	ft_putint_fd((int)(obj->shader / 2), fd);
	write(fd, "</shader>\n", 10);
	write(fd, "</object>\n\n", 11);
}

static void	export_object_part2(t_obj *obj, int fd)
{
	ft_putfloat_fd((float)obj->rot.x, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->rot.y, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->rot.z, fd);
	write(fd, "</rotation>\n", 12);
	write(fd, "\t<color-rgb>", 12);
	ft_putfloat_fd((float)obj->clr.x * 255., fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->clr.y * 255., fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->clr.z * 255., fd);
	write(fd, "</color-rgb>\n", 13);
	write(fd, "\t<opacity>", 10);
	ft_putfloat_fd((float)obj->opacity, fd);
	write(fd, "</opacity>\n", 11);
	if (obj->forme == T_SPHERE || obj->forme == T_CYLINDER ||
	obj->forme == T_CONE || obj->forme == T_TORUS)
	{
		write(fd, "\t<radius>", 9);
		ft_putfloat_fd((float)obj->radius, fd);
		write(fd, "</radius>\n", 10);
	}
	export_object_dimensions(obj, fd);
	export_object_part3(obj, fd);
}

void		export_object(t_obj *obj, int fd)
{
	write(fd, "<object>\n", 9);
	write(fd, "\t<name>", 7);
	write(fd, (char *)obj->n, ft_strlen((char *)obj->n));
	write(fd, "</name>\n", 8);
	write(fd, "\t<type>", 7);
	export_shape_object(obj->forme, fd);
	write(fd, "</type>\n", 8);
	write(fd, "\t<preset>", 9);
	export_material_object(obj->preset, fd);
	write(fd, "</preset>\n", 10);
	write(fd, "\t<visibility>", 13);
	(obj->visibility == 1) ? write(fd, "True", 4) : write(fd, "False", 5);
	write(fd, "</visibility>\n", 14);
	write(fd, "\t<position>", 11);
	ft_putfloat_fd((float)obj->pos.x, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->pos.y, fd);
	write(fd, " ", 1);
	ft_putfloat_fd((float)obj->pos.z, fd);
	write(fd, "</position>\n", 12);
	write(fd, "\t<rotation>", 11);
	export_object_part2(obj, fd);
}
