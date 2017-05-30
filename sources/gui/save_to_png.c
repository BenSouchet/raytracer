/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_to_png.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:03:17 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 10:46:35 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		save_to_png(t_rt *rt)
{
	static int	id = 1;

	rt->s_temp = SDL_ConvertSurfaceFormat(
	(rt->scn->sp_mode != 0) ? rt->s_effct : rt->s_rend, SDL_PF2, 0);
	(id == 1) ? system("mkdir -p saved_images") : 1;
	rt->ui->tmp = ft_strf("test -e saved_images/%s%d.png", IMG, id);
	while (system(rt->ui->tmp) == 0)
	{
		free(rt->ui->tmp);
		rt->ui->tmp = ft_strf("test -e saved_images/%s%d.png", IMG, ++id);
	}
	free(rt->ui->tmp);
	rt->ui->n_save = ft_strf("%s%d.bmp", IMG, id);
	rt->ui->tmp = ft_strjoin("temporary/", rt->ui->n_save, 'N');
	SDL_SaveBMP(rt->s_temp, rt->ui->tmp);
	free(rt->ui->tmp);
	rt->ui->tmp = ft_strf("sips -s format png temporary/%s --out \
	saved_images/%s%d.png 2&>/dev/null >/dev/null", rt->ui->n_save, IMG, id);
	system(rt->ui->tmp);
	free(rt->ui->tmp);
	rt->ui->tmp = ft_strf("rm temporary/%s", rt->ui->n_save);
	free(rt->ui->n_save);
	system(rt->ui->tmp);
	free(rt->ui->tmp);
	SDL_FreeSurface(rt->s_temp);
}
