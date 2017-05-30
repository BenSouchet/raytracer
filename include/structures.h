/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:33:17 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:24:46 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libcl.h"

typedef struct s_scene	t_scene;
typedef struct s_rt		t_rt;

/*
** ---------------------------- Scene Elements ---------------------------------
*/

typedef struct		s_obj
{
	cl_short		id;
	cl_char			*n;
	cl_short		title;
	cl_char			type;
	cl_short		forme;
	cl_short		preset;
	cl_float3		pos;
	cl_float3		rot;
	cl_float3		clr;
	cl_float		opacity;
	cl_short		focal;
	cl_float		radius;
	cl_float		lenght;
	cl_float		width;
	cl_float		height;
	cl_short		visibility;
	cl_float		intensity;
	cl_short		specular;
	cl_float		reflex;
	cl_short		refrac;
	cl_short		shader;
	SDL_Rect		r_ol;
	struct s_obj	*next;
}					t_obj;

/*
** -------------------------- Global Structures --------------------------------
*/

typedef struct		s_parser
{
	int				i;
	int				t_i;
	double			t_d;
	unsigned		t_u;
	int				copy;
	cl_float3		vec;
	char			*buf;
	char			*line;
	short			n[50];
	short			t[20];
	char			*b_o;
	char			*b_c;
	t_obj			*obj_tmp;
}					t_parser;

struct				s_scene
{
	cl_short		redraw;
	cl_short		aa;
	cl_float		ambient;
	cl_short		m_ref;
	cl_char			*name;
	t_obj			*o;
	t_obj			*b_lgts;
	t_obj			*b_objs;
	cl_short		n_cams;
	cl_short		n_lgts;
	cl_short		n_objs;
	cl_short		n_elms;
	t_obj			*b_outliner;
	t_obj			*s_elem;
	t_obj			*c_cam;
	cl_short		sp_mode;
	cl_short		t[15];
	cl_short		ot[10];
	cl_short		lt[5];
};

typedef struct		s_ui
{
	short			t_c;
	cl_float3		t_v;
	cl_float3		t_v2;
	t_hsv			hsv;
	char			c_num;
	char			*tmp;
	char			*c_name;
	char			*r_dim;
	char			m_visible;
	char			b_hover;
	char			b_se_hover;
	char			b_se_down;
	char			case_active;
	char			b_down;
	char			c_hover;
	char			c_down;
	char			ra_hover;
	char			ra_down;
	char			b_sp_hover;
	char			b_sp_active;
	char			*n_save;
	char			save_num;
	char			b_state[19];
	char			nav_state;
	short			id;
	short			k_edit;
	t_obj			*c_elem;
	SDL_Point		p_tmp;
	SDL_Rect		t_rect;
	SDL_Color		c_clr[3];
	SDL_Rect		area[16];
	SDL_Rect		ra_rect[11];
	SDL_Rect		b_rect[20];
	SDL_Rect		cam_b_rect[8];
	SDL_Rect		lgt_b_rect[12];
	SDL_Rect		obj_b_rect[19];
	SDL_Rect		param_b_rect[3];
	SDL_Rect		*b_se_rect;
	SDL_Rect		*case_rect;
	SDL_Rect		r_hover;
	SDL_Surface		*s_tmp;
	SDL_Surface		*s_ui;
	SDL_Surface		*s_cam;
	SDL_Surface		*s_ver;
	TTF_Font		**font;
}					t_ui;

struct				s_rt
{
	char			*filename;
	char			*w_title;
	char			**err;
	char			**inf;

	char			run;

	SDL_Window		*win;

	t_parser		*prs;
	t_scene			*scn;

	t_timer			*fps;

	SDL_Event		event;
	SDL_Point		m_pos;
	t_ui			*ui;

	char			n_info;

	SDL_Rect		r_info;
	int				t_info;

	SDL_Cursor		*cursor;

	SDL_Surface		*w_icon;

	SDL_Surface		*s_back;

	SDL_Surface		*s_temp;

	SDL_Rect		r_view;
	SDL_Rect		r_view_m;
	SDL_Surface		*s_rend;
	SDL_Surface		*s_effct;
	SDL_Texture		*t_rend;

	char			render;
};

typedef struct		s_client
{
	int				fd;
	int				*buffer;
	struct s_client	*next;
	char			status;
}					t_client;

typedef struct		s_cl
{
	t_cl_info		info;
	t_cl_krl		main_krl;
	cl_mem			objs;
	cl_mem			lgts;
	short			n_objs;
	short			n_lgts;
	int				sockfd;
	cl_float2		offs;
	pthread_t		accept_thread;
	t_client		*cli_list;
}					t_cl;

#endif
