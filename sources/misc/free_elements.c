/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:49:22 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 12:26:52 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	free_gui(t_rt *rt)
{
	free(rt->ui->c_name);
	free(rt->ui->r_dim);
	SDL_FreeSurface(rt->ui->s_ui);
	TTF_CloseFont(rt->ui->font[0]);
	TTF_CloseFont(rt->ui->font[1]);
	free(rt->ui->font);
	free(rt->ui);
}

static void	free_scene(t_rt *rt)
{
	free(rt->scn->name);
	free(rt->scn);
}

int			free_elements(t_rt *rt)
{
	SDL_DestroyWindow(rt->win);
	free(rt->err);
	free(rt->prs->buf);
	free(rt->prs);
	free(rt->fps);
	SDL_FreeCursor(rt->cursor);
	free_gui(rt);
	free_scene(rt);
	SDL_FreeSurface(rt->w_icon);
	SDL_FreeSurface(rt->s_rend);
	SDL_FreeSurface(rt->s_effct);
	TTF_Quit();
	SDL_Quit();
	exit(0);
	return (0);
}
