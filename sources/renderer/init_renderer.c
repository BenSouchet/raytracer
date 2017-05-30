/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:49:37 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:18:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_window_elements(t_rt *rt)
{
	rt->scn->redraw = 0;
	rt->r_view = (SDL_Rect){232, 84, 816, 588};
	rt->r_info = (SDL_Rect){215, 690, 850, 30};
	rt->cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
	rt->ui->s_ui = IMG_Load("./assets/images/ui.png");
	rt->ui->font[0] = TTF_OpenFont("./assets/font/SourceCodePro.ttf", 14);
	rt->ui->font[1] = TTF_OpenFont("./assets/font/SourceCodePro.ttf", 12);
	rt->s_back = SDL_GetWindowSurface(rt->win);
	rt->s_rend = SDL_CreateRGBSurfaceWithFormat(0, REND_W, REND_H, 32, SDL_PF);
	rt->s_effct = SDL_CreateRGBSurfaceWithFormat(0, REND_W, REND_H, 32, SDL_PF);
	rt->ui->s_ver = TTF_RenderText_Blended(rt->ui->font[0], WIN_VERSION,
	(SDL_Color){109, 125, 145, 255});
	fsdl_fill_rect(rt->s_back, (SDL_Rect){0, 0, 1280, 720}, WIN_BG);
	SDL_SetCursor(rt->cursor);
}

static void	init_fps_structure(t_rt *rt)
{
	rt->fps->limit = MAX_FPS;
	rt->fps->framelimit = 0;
	rt->fps->fps = 0;
	rt->fps->update = 0;
	rt->fps->current = 0;
}

void		init_renderer(t_rt *rt)
{
	rt->run = 1;
	rt->n_info = 0;
	rt->t_info = 0;
	rt->scn->s_elem = NULL;
	init_fps_structure(rt);
	fsdl_fps_limit(rt->fps);
	init_window_elements(rt);
	init_gui_structure(rt);
	draw_current_camera_name(rt, 0);
	draw_scene_parameters(rt);
	draw_outliner(rt, -1, 0);
	draw_renderer_info(rt);
	draw_info_bar(rt);
}
