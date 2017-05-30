/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:10:20 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/12 18:10:52 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	export_scene_parameters(t_scene *scn, int fd)
{
	write(fd, "<!--------- Global Settings ---------->\n\n", 41);
	write(fd, "<scene>\n", 8);
	write(fd, "\t<name>", 7);
	write(fd, (char *)scn->name, ft_strlen((char *)scn->name));
	write(fd, "</name>\n", 8);
	write(fd, "\t<ambient>", 10);
	ft_putfloat_fd((float)scn->ambient, fd);
	write(fd, "</ambient>\n", 11);
	write(fd, "\t<max-reflexion>", 16);
	ft_putint_fd((int)scn->m_ref, fd);
	write(fd, "</max-reflexion>\n", 17);
	write(fd, "</scene>\n\n", 10);
}

static void	export_elements(t_rt *rt, int fd)
{
	t_obj		*objs;

	export_scene_parameters(rt->scn, fd);
	write(fd, "<!------------ Camera(s) ------------->\n\n", 41);
	objs = rt->scn->o->next;
	while (objs != NULL && objs->type == 'C')
	{
		export_camera(objs, fd);
		objs = objs->next;
	}
	write(fd, "<!------------ Light(s) -------------->\n\n", 41);
	objs = rt->scn->b_lgts->next;
	while (objs != NULL && objs->type == 'L')
	{
		export_light(objs, fd);
		objs = objs->next;
	}
	write(fd, "<!------------ Object(s) ------------->\n\n", 41);
	objs = rt->scn->b_objs->next;
	while (objs != NULL)
	{
		export_object(objs, fd);
		objs = objs->next;
	}
}

void		export_config_file(t_rt *rt)
{
	char		*tmp;
	int			fd;

	tmp = ft_strf("> %s", rt->filename);
	system(tmp);
	free(tmp);
	fd = open(rt->filename, O_WRONLY | O_APPEND);
	export_elements(rt, fd);
	close(fd);
}
