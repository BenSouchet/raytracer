/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:13:35 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 15:49:06 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			add_sp_mode(t_rt *rt)
{
	redraw_aa(rt);
	if (rt->scn->sp_mode == 1)
		add_pixel_art_effect(rt);
	else if (rt->scn->sp_mode == 2)
		add_saturate_effect(rt);
	else if (rt->scn->sp_mode == 3)
		add_sepia_effect(rt, 0, 0, 0);
	else if (rt->scn->sp_mode == 4)
		add_black_n_white_effect(rt);
	else if (rt->scn->sp_mode == 5)
		add_sobel_effect(rt, 0, 0, 0);
	else if (rt->scn->sp_mode == 6)
		add_reverse_colors_effect(rt);
	else if (rt->scn->sp_mode == 7)
		add_cartoon_effect(rt, 0, 0, 0);
	SDL_LowerBlit(rt->s_effct, &(SDL_Rect){(rt->r_view.x - 18), 0,
	rt->r_view.w, rt->r_view.h}, rt->s_back, &rt->r_view);
	return (1);
}

int			add_render_frame(t_rt *rt)
{
	redraw_aa(rt);
	SDL_LowerBlit(rt->s_rend, &(SDL_Rect){(rt->r_view.x - 18), 0,
	rt->r_view.w, rt->r_view.h}, rt->s_back, &rt->r_view);
	return (1);
}

int			lol_cat(void *data, SDL_Event *event)
{
	if (event->type == SDL_KEYUP)
	{
		SDL_FlushEvent(SDL_KEYDOWN);
		if (((t_rt *)data)->ui->case_active != -1)
			((t_rt *)data)->scn->redraw = 1;
	}
	if (event->type == 0x402)
		((t_rt *)data)->scn->redraw = 1;
	return (1);
}

static int	global_loop(t_rt *rt, t_cl *cl)
{
	while (rt->run)
	{
		if (SDL_PollEvent(&rt->event))
		{
			SDL_AddEventWatch(lol_cat, rt);
			handle_events(rt, cl);
			if (rt->scn->redraw)
			{
				cl_main_krl_exec(cl, &rt->scn->aa);
				cl_copy_image_buffer(cl, rt->s_rend->pixels);
				(rt->scn->sp_mode) ? add_sp_mode(rt) : add_render_frame(rt);
				rt->scn->redraw = 0;
			}
		}
		SDL_UpdateWindowSurface(rt->win);
		fsdl_fps_limit(rt->fps);
		fsdl_fps_counter(rt->fps);
	}
	return (free_elements(rt));
}

int			create_window(t_rt *rt, t_cl *cl)
{
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (error(rt, 29));
	if (!(rt->w_icon = IMG_Load(WIN_ICON)))
		return (error(rt, 32));
	rt->w_title = ft_strjoin(WIN_TITLE, (char *)rt->scn->name, 'N');
	if (!(rt->win = SDL_CreateWindow(rt->w_title, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0)))
		return (error(rt, 30));
	SDL_SetWindowIcon(rt->win, rt->w_icon);
	free(rt->w_title);
	init_renderer(rt);
	if (!(cl_main_krl_update_buffers(cl, rt->scn)
		&& cl_main_krl_update_camera(cl, rt->scn->c_cam)
		&& cl_main_krl_exec(cl, &rt->scn->aa)
		&& cl_copy_image_buffer(cl, rt->s_rend->pixels)))
		return (error(rt, 42));
	cluster_init(cl);
	add_render_frame(rt);
	return (global_loop(rt, cl));
}
