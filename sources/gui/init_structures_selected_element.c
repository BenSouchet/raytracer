/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures_selected_element.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:05:05 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 19:25:48 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_gui_selected_camera_buttons(t_ui *ui)
{
	ui->cam_b_rect[0] = (SDL_Rect){1088, 309, 170, 22};
	ui->cam_b_rect[1] = (SDL_Rect){1205, 160, 53, 21};
	ui->cam_b_rect[2] = (SDL_Rect){1088, 212, 53, 21};
	ui->cam_b_rect[3] = (SDL_Rect){1147, 212, 52, 21};
	ui->cam_b_rect[4] = (SDL_Rect){1205, 212, 53, 21};
	ui->cam_b_rect[5] = (SDL_Rect){1088, 265, 53, 21};
	ui->cam_b_rect[6] = (SDL_Rect){1147, 265, 52, 21};
	ui->cam_b_rect[7] = (SDL_Rect){1205, 265, 53, 21};
}

void		init_gui_selected_light_buttons(t_ui *ui)
{
	ui->lgt_b_rect[0] = (SDL_Rect){1088, 389, 170, 22};
	ui->lgt_b_rect[1] = (SDL_Rect){1205, 160, 53, 21};
	ui->lgt_b_rect[2] = (SDL_Rect){1205, 187, 53, 21};
	ui->lgt_b_rect[3] = (SDL_Rect){1088, 239, 53, 21};
	ui->lgt_b_rect[4] = (SDL_Rect){1147, 239, 52, 21};
	ui->lgt_b_rect[5] = (SDL_Rect){1205, 239, 53, 21};
	ui->lgt_b_rect[6] = (SDL_Rect){1088, 292, 53, 21};
	ui->lgt_b_rect[7] = (SDL_Rect){1147, 292, 52, 21};
	ui->lgt_b_rect[8] = (SDL_Rect){1205, 292, 53, 21};
	ui->lgt_b_rect[9] = (SDL_Rect){1088, 345, 53, 21};
	ui->lgt_b_rect[10] = (SDL_Rect){1147, 345, 52, 21};
	ui->lgt_b_rect[11] = (SDL_Rect){1205, 345, 53, 21};
}

void		init_gui_selected_object_buttons(t_ui *ui)
{
	ui->obj_b_rect[0] = (SDL_Rect){1088, 550, 170, 22};
	ui->obj_b_rect[1] = (SDL_Rect){1173, 160, 85, 21};
	ui->obj_b_rect[2] = (SDL_Rect){1173, 214, 85, 21};
	ui->obj_b_rect[3] = (SDL_Rect){1173, 241, 85, 21};
	ui->obj_b_rect[4] = (SDL_Rect){1173, 268, 85, 21};
	ui->obj_b_rect[5] = (SDL_Rect){1173, 295, 85, 21};
	ui->obj_b_rect[6] = (SDL_Rect){1088, 347, 53, 21};
	ui->obj_b_rect[7] = (SDL_Rect){1147, 347, 52, 21};
	ui->obj_b_rect[8] = (SDL_Rect){1205, 347, 53, 22};
	ui->obj_b_rect[9] = (SDL_Rect){1088, 400, 53, 21};
	ui->obj_b_rect[10] = (SDL_Rect){1147, 400, 52, 21};
	ui->obj_b_rect[11] = (SDL_Rect){1205, 400, 53, 21};
	ui->obj_b_rect[12] = (SDL_Rect){1088, 453, 53, 21};
	ui->obj_b_rect[13] = (SDL_Rect){1147, 453, 52, 21};
	ui->obj_b_rect[14] = (SDL_Rect){1205, 453, 53, 21};
	ui->obj_b_rect[15] = (SDL_Rect){1088, 506, 53, 21};
	ui->obj_b_rect[16] = (SDL_Rect){1147, 506, 52, 21};
	ui->obj_b_rect[17] = (SDL_Rect){1205, 506, 53, 21};
	ui->obj_b_rect[18] = (SDL_Rect){1173, 187, 85, 21};
}

void		init_gui_selected_scene_parameters(t_ui *ui)
{
	ui->param_b_rect[0] = (SDL_Rect){139, 100, 53, 21};
	ui->param_b_rect[1] = (SDL_Rect){139, 127, 53, 21};
	ui->param_b_rect[2] = (SDL_Rect){139, 154, 53, 21};
}
