/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buttons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 15:43:42 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 16:04:56 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_buttons_rect(t_ui *ui)
{
	ui->b_rect[0] = (SDL_Rect){225, 25, 72, 34};
	ui->b_rect[1] = (SDL_Rect){318, 25, 34, 34};
	ui->b_rect[2] = (SDL_Rect){370, 25, 34, 34};
	ui->b_rect[3] = (SDL_Rect){411, 25, 34, 34};
	ui->b_rect[4] = (SDL_Rect){452, 25, 33, 34};
	ui->b_rect[5] = (SDL_Rect){504, 25, 34, 34};
	ui->b_rect[6] = (SDL_Rect){545, 25, 33, 34};
	ui->b_rect[7] = (SDL_Rect){585, 25, 34, 34};
	ui->b_rect[8] = (SDL_Rect){626, 25, 34, 34};
	ui->b_rect[9] = (SDL_Rect){667, 25, 33, 34};
	ui->b_rect[10] = (SDL_Rect){707, 25, 34, 34};
	ui->b_rect[11] = (SDL_Rect){762, 25, 34, 34};
	ui->b_rect[12] = (SDL_Rect){803, 25, 34, 34};
	ui->b_rect[13] = (SDL_Rect){844, 25, 34, 34};
	ui->b_rect[14] = (SDL_Rect){885, 25, 34, 34};
	ui->b_rect[15] = (SDL_Rect){940, 25, 34, 34};
	ui->b_rect[16] = (SDL_Rect){981, 25, 34, 34};
	ui->b_rect[17] = (SDL_Rect){1022, 25, 34, 34};
}

static void	init_buttons_state(t_ui *ui)
{
	ui->b_state[0] = 0;
	ui->b_state[1] = 0;
	ui->b_state[2] = 0;
	ui->b_state[3] = 0;
	ui->b_state[4] = 0;
	ui->b_state[5] = 0;
	ui->b_state[6] = 0;
	ui->b_state[7] = 0;
	ui->b_state[8] = 0;
	ui->b_state[9] = 0;
	ui->b_state[10] = 0;
	ui->b_state[11] = 4;
	ui->b_state[12] = 4;
	ui->b_state[13] = 4;
	ui->b_state[14] = 4;
	ui->b_state[15] = 2;
	ui->b_state[16] = 2;
	ui->b_state[17] = 0;
}

static void	disable_buttons(t_rt *rt)
{
	draw_button(rt, 6, 3);
	draw_button(rt, 10, 3);
	draw_button(rt, 11, 3);
	draw_button(rt, 12, 3);
	draw_button(rt, 13, 3);
	draw_button(rt, 14, 3);
	draw_button(rt, 15, 2);
	draw_button(rt, 16, 2);
}

void		init_buttons(t_rt *rt)
{
	rt->ui->k_edit = 0;
	rt->ui->b_sp_hover = -1;
	rt->ui->b_sp_active = -1;
	rt->ui->case_active = -1;
	rt->ui->case_rect = NULL;
	init_buttons_rect(rt->ui);
	init_buttons_state(rt->ui);
	disable_buttons(rt);
	init_gui_selected_camera_buttons(rt->ui);
	init_gui_selected_light_buttons(rt->ui);
	init_gui_selected_object_buttons(rt->ui);
	init_gui_selected_scene_parameters(rt->ui);
	rt->ui->r_hover = (SDL_Rect){13, 233, 188, 29};
	rt->ui->c_clr[0] = (SDL_Color){44, 53, 64, 255};
	rt->ui->c_clr[1] = (SDL_Color){48, 58, 69, 255};
	rt->ui->c_clr[2] = (SDL_Color){40, 48, 57, 255};
}
