/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:38:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 15:47:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libfmt.h"
#include "test_krl.h"

static int	check(t_rt *rt, int end)
{
	rt->ui->id = 0;
	rt->scn->o = lst_new_camera(rt, rt->scn->o, -1);
	rt->scn->o = lst_new_light(rt, rt->scn->o, -2);
	rt->scn->o = lst_new_object(rt, rt->scn->o, -3, 0);
	while (end != -1 && rt->prs->buf[rt->prs->i] != 0)
	{
		if ((end = check_tags(rt, BO_S, BC_S)) > 0)
			end = set_scene(rt, end, 0);
		else if (end != -1 && (end = check_tags(rt, BO_C, BC_C)) > 0)
			end = add_camera(rt, end);
		else if (end != -1 && (end = check_tags(rt, BO_L, BC_L)) > 0)
			end = add_light(rt, end);
		else if (end != -1 && (end = check_tags(rt, BO_O, BC_O)) > 0)
			end = add_object(rt, end);
		else if (end > -1)
			return (error(rt, 8));
	}
	end = (end != -1 && rt->scn->n_cams == 0) ? error(rt, 17) : end;
	end = (end != -1 && rt->scn->n_lgts == 0) ? error(rt, 18) : end;
	end = (end != -1 && rt->scn->n_objs == 0) ? error(rt, 19) : end;
	if (end != -1 && !rt->scn->name)
		rt->scn->name = (cl_char *)ft_name(rt->filename, ".rt");
	rt->scn->c_cam = rt->scn->o->next;
	rt->scn->b_outliner = rt->scn->o;
	return (end);
}

static int	execute(t_rt *rt, t_cl *cl, int fd)
{
	rt->prs->copy = 1;
	if (!(rt->prs->buf = (char *)malloc(sizeof(char))))
		return (error(rt, 0));
	rt->prs->buf[0] = 0;
	while (get_next_line(fd, &rt->prs->line) > 0)
		if ((rt->prs->line =
		clear_line(rt->prs, rt->prs->line, 0, -1)) != NULL)
			rt->prs->buf = ft_strjoin(rt->prs->buf, rt->prs->line, 'B');
	if (close(fd) == -1)
		return (error(rt, 3));
	if (check(rt, 0) == -1)
		return (-1);
	if (!cl_main_krl_init(cl))
		return (error(rt, 42));
	return (create_window(rt, cl));
}

int			main(int ac, char **av)
{
	t_cl		cl;
	t_rt		rt;

	init_errors(&rt, 0);
	if (init_structures(&rt) != 0)
		return (-1);
	if ((ac != 2 && ac != 3) ||
		(ac == 3 && !ft_lcmp(av[2], "-v") && !ft_lcmp(av[2], "-verbose")))
		return (error(&rt, 1));
	if (!ft_strchr_end(av[1], ".rt"))
		return (error(&rt, 2));
	if ((ac = open(av[1], O_RDONLY)) == -1)
		return (error(&rt, 3));
	rt.filename = av[1];
	return (execute(&rt, &cl, ac));
}
