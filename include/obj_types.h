/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:36:46 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:47:55 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_TYPES_H
# define OBJ_TYPES_H

/*
** define des type d'objets
*/

# define T_SPHERE		1
# define T_CUBE			2
# define T_CYLINDER		3
# define T_PLANE		4
# define T_CONE			5
# define T_TORUS		6
# define T_PYRAMID		7
# define T_TETRAHEDRON	8
# define T_OCTAHEDRON	9
# define T_MOEBIUS		10
# define T_DISK			11
# define T_TRIANGLE		12

# define T_DIFFUSE		0
# define T_DIRECTIONAL	1
# define T_SPOT			2

# define T_LAMBERT		0
# define T_BLINN		1
# define T_PHONG		2
# define T_CUSTOM		3

/*
** define des type de shaders
*/

# define NONE			0
# define STAR			1
# define WOOD			2
# define MARBRE1		3
# define MARBRE2		4
# define MARBRE3		5
# define MARBRE4		6
# define MARBRE5		7
# define MARBRE6		8
# define MARBRE7		9
# define SKYSTAR		10
# define SKYDAY			11

# define CAM_OTHER		0
# define CAM_SKYDAY		1
# define CAM_SKYNIGHT	2

#endif
