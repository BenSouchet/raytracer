/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 22:09:34 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/12 20:11:50 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*shape_object(short shape)
{
	if (shape == T_SPHERE)
		return ("Sphere ");
	else if (shape == T_CUBE)
		return ("Cube ");
	else if (shape == T_CYLINDER)
		return ("Cylinder ");
	else if (shape == T_PLANE)
		return ("Plane ");
	else if (shape == T_CONE)
		return ("Cone ");
	else if (shape == T_TORUS)
		return ("Torus ");
	else if (shape == T_PYRAMID)
		return ("Pyramid ");
	else if (shape == T_TETRAHEDRON)
		return ("Tetrahedron ");
	else if (shape == T_OCTAHEDRON)
		return ("Octahedron ");
	else if (shape == T_MOEBIUS)
		return ("Moebius ");
	return ("Object ");
}

char		*shape_object_ws(short shape)
{
	if (shape == T_SPHERE)
		return ("Sphere");
	else if (shape == T_CUBE)
		return ("Cube");
	else if (shape == T_CYLINDER)
		return ("Cylinder");
	else if (shape == T_PLANE)
		return ("Plane");
	else if (shape == T_CONE)
		return ("Cone");
	else if (shape == T_TORUS)
		return ("Torus");
	else if (shape == T_PYRAMID)
		return ("Pyramid");
	else if (shape == T_TETRAHEDRON)
		return ("Tetrahedron");
	else if (shape == T_OCTAHEDRON)
		return ("Octahedron");
	else if (shape == T_MOEBIUS)
		return ("Moebius");
	return ("Object");
}

int			export_material_object(short material, int fd)
{
	if (material == 0)
		return (write(fd, "Earth", 5));
	else if (material == 1)
		return (write(fd, "Sun", 3));
	else if (material == 2)
		return (write(fd, "Moon", 4));
	else if (material == 3)
		return (write(fd, "Jupiter", 7));
	return (write(fd, "No Preset", 9));
}

char		*light_type(short type)
{
	if (type == T_DIFFUSE)
		return ("Point Light ");
	else if (type == T_DIRECTIONAL)
		return ("Directional Light ");
	else if (type == T_SPOT)
		return ("Spot Light ");
	return ("Light ");
}
