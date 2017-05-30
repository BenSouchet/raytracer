/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:22:46 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <assert.h>

/*
** --------------------------------- OpenCL ------------------------------------
*/

# ifdef __APPLE__
#  include "OpenCL/opencl.h"
# else
#  include "CL/cl.h"
# endif

/*
** -------------------------- Internal Libraries -------------------------------
*/

# include "../libraries/fsdl/include/fsdl.h"
# include "../libraries/libft/include/libft.h"

/*
** -------------------------- Internal Frameworks ------------------------------
*/

# include "../frameworks/SDL2.framework/headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/headers/SDL_ttf.h"
# include "../frameworks/SDL2_image.framework/headers/SDL_image.h"

/*
** --------------------------- Internal Headers --------------------------------
*/

# include "parameters.h"
# include "infos_messages.h"
# include "errors_messages.h"
# include "xml_elements.h"
# include "structures.h"

/*
** -----------------------------------------------------------------------------
** --------------------------------- Parser ------------------------------------
** -----------------------------------------------------------------------------
*/

void				init_cam(t_rt *rt, short pos, short t);
void				init_light(t_rt *rt, short pos, short t);
void				init_object(t_rt *rt, short pos, short t);
int					init_structures(t_rt *rt);

int					reset_tags(t_parser *p);

char				*clear_line(t_parser *p, char *str, int i, int n);

int					check_tags(t_rt *rt, char *b_open, char *b_close);

int					check_scene(t_rt *rt);
int					check_camera(t_rt *rt, t_obj *tmp, short i);
int					check_light(t_rt *rt, t_obj *tmp, short i);
int					check_object(t_rt *rt, t_obj *tmp, short i);

int					get_i(t_rt *rt, int b_end, char *s, char *e);
int					get_d(t_rt *rt, int b_end, char *s, char *e);
int					get_v(t_rt *rt, int b_e, char *s, char *e);
int					get_b(t_rt *rt, int b_end, char *s, char *e);
int					get_h(t_rt *rt, int b_end, char *s, char *e);

char				*get_s(t_parser *r, int b_end, int b_size);
int					get_m(t_rt *rt, int b_end, char *s, char *e);
int					get_t(t_rt *rt, int b_end, char *s, char *e);
int					get_lt(t_rt *rt, int b_end, char *s, char *e);

int					set_scene(t_rt *rt, int b_end, int e);
int					add_camera(t_rt *rt, int b_end);
int					add_light(t_rt *rt, int b_end);
int					add_object(t_rt *rt, int b_end);

char				*light_type(short type);
char				*shape_object(short shape);
int					export_shape_object(short shape, int fd);
int					export_material_object(short material, int fd);

t_obj				*set_default_parameters(t_obj *obj, char type, int title);
t_obj				*set_element_parameters(t_obj *obj, t_obj *tmp, char type,
					int title);

int					add_global_parameters(t_rt *r, t_parser *p, t_obj *obj,
					int e);
int					add_camera_parameters(t_rt *rt, t_obj *obj, int b_e, int e);
int					add_light_parameters(t_rt *rt, t_obj *obj, int b_e, int e);
int					add_object_parameters(t_rt *rt, t_obj *obj, int b_e, int e);

/*
** -----------------------------------------------------------------------------
** ---------------------------------- GUI --------------------------------------
** -----------------------------------------------------------------------------
*/

void				init_gui_structure(t_rt *rt);
void				init_buttons(t_rt *rt);
void				init_gui_selected_camera_buttons(t_ui *ui);
void				init_gui_selected_light_buttons(t_ui *ui);
void				init_gui_selected_object_buttons(t_ui *ui);
void				init_gui_selected_scene_parameters(t_ui *ui);

void				draw_panel(t_rt *rt, int p, int type);
void				draw_button(t_rt *rt, int b_num, int type);
void				draw_se_button(t_rt *rt, int b_num, char etype, int type);

void				draw_renderer_info(t_rt *rt);
void				draw_current_camera_name(t_rt *rt, short type);
int					draw_state_frame(t_rt *rt);
int					draw_info_bar(t_rt *rt);

void				draw_scene_parameters(t_rt *rt);
void				draw_sp_element(t_rt *rt, int b_num, int mode);

void				draw_outliner(t_rt *rt, int i, int max);
void				draw_outliner_element(t_rt *rt, t_obj *obj, int state);
void				draw_outliner_title(t_rt *rt, int i);
void				draw_nav_element(t_rt *rt, int state);
void				draw_top_nav_button(t_rt *rt, int state);
void				draw_bottom_nav_button(t_rt *rt, int state);

void				draw_selected_element(t_rt *rt);
void				draw_no_selected_element(t_rt *rt);
void				draw_parameter(t_rt *rt, char *tmp, SDL_Rect rect, int t);
void				draw_selected_camera(t_rt *rt, t_obj *obj);
void				draw_selected_light(t_rt *rt, t_obj *obj);
void				draw_selected_object(t_rt *rt, t_obj *obj);
void				draw_dimensions_parameter(t_rt *rt, t_obj *o);

void				redraw_current_element(t_rt *rt, t_cl *cl, char *str);

void				redraw_case_active(t_rt *rt, int mode);
void				draw_case_active(t_rt *rt, char *tmp, SDL_Rect rect, int t);

void				draw_materials(t_rt *rt, char type);

void				draw_special_mode(t_rt *rt, int r_num, int type);

void				save_to_png(t_rt *rt);

void				draw_parameter_static(t_rt *rt, char *tmp, int y, int mode);
void				redraw_aa(t_rt *rt);

/*
** -----------------------------------------------------------------------------
** --------------------------------- OpenCL ------------------------------------
** -----------------------------------------------------------------------------
*/

bool				cl_main_krl_init(t_cl *cl);

bool				cl_main_krl_exec(t_cl *cl, short *n_aa);

bool				cl_main_krl_update_camera(t_cl *cl, t_obj *obj);
bool				cl_main_krl_update_buffers(t_cl *cl, t_scene *scene);

bool				cl_copy_image_buffer(t_cl *cl, void *buffer);

/*
** -----------------------------------------------------------------------------
** ------------------------------- Renderer ------------------------------------
** -----------------------------------------------------------------------------
*/

void				init_renderer(t_rt *rt);

int					create_window(t_rt *rt, t_cl *cl);

int					add_render_frame(t_rt *rt);
void				render_loop(t_rt *rt);

bool				scene_init_rendering(t_rt *rt, t_cl *cl);

/*
** -----------------------------------------------------------------------------
** ----------------------------- Special Modes ---------------------------------
** -----------------------------------------------------------------------------
*/

void				add_sepia_effect(t_rt *rt, short r, short g, short b);
void				add_black_n_white_effect(t_rt *rt);
void				add_cartoon_effect(t_rt *rt, short s, short x_g, short y_g);
void				add_reverse_colors_effect(t_rt *rt);
void				add_sobel_effect(t_rt *rt, short sum, short x, short y);
void				add_pixel_art_effect(t_rt *rt);
void				add_saturate_effect(t_rt *rt);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Handle -------------------------------------
** -----------------------------------------------------------------------------
*/

/*
** ---------------------------- Handle Events ----------------------------------
*/

void				handle_events(t_rt *rt, t_cl *cl);

/*
** --------------------------- Handle Elements ---------------------------------
*/
char				*shape_object(short shape);
char				*shape_object_ws(short shape);
void				set_default_element(t_rt *rt, t_cl *cl, char type);
void				add_new_camera(t_rt *rt, t_obj *tmp);
void				add_new_light(t_rt *rt, t_obj *tmp, short type);
void				add_new_object(t_rt *rt, t_obj *tmp, short type);
void				add_new_shader(t_obj *obj, short type);
/*
** ------------------------------ Handle GUI -----------------------------------
*/

void				handle_buttons(t_rt *rt);
void				handle_buttons_down(t_rt *rt, t_cl *cl);

void				execute_button(t_rt *rt, int button, t_cl *cl);

/*
** --------------------------- Handle Outliner ---------------------------------
*/

void				handle_outliner(t_rt *rt, int pos, int tmp, int type);
void				handle_outliner_down(t_rt *rt);

/*
** ------------------------- Handle Special Mode -------------------------------
*/

void				handle_special_modes_down(t_rt *rt);
void				handle_special_mode(t_rt *rt, int i);

/*
** ----------------------------- Handle Mouse ----------------------------------
*/

void				handle_left_click_up(t_rt *rt);
void				handle_left_click_down(t_rt *rt, t_cl *cl);

void				handle_right_click_down(t_rt *rt, t_cl *cl);

void				handle_double_click_down(t_rt *rt, t_cl *cl);

void				handle_motion_mouse(t_rt *rt);

/*
** ------------------------ Handle Selected Element ----------------------------
*/

void				handle_selected_element(t_rt *rt);
void				handle_selected_element_down(t_rt *rt, t_cl *cl);

void				delete_current_element(t_rt *rt, t_cl *cl,
					t_obj *nav, t_obj *tmp);

/*
** ------------------------ Handle Scene Parameters ----------------------------
*/

void				handle_scene_parameters(t_rt *rt);

/*
** --------------------------- Handle Keyboard ---------------------------------
*/

void				handle_keyboard(t_rt *rt, t_cl *cl);
void				update_se_box_plus(t_rt *rt, t_cl *cl);
void				update_se_box_minus(t_rt *rt, t_cl *cl);

void				update_se_light_box_plus_part2(t_rt *rt);
void				update_se_light_box_minus_part2(t_rt *rt);

/*
** ------------------------- Handle Linked Lints -------------------------------
*/

t_obj				*lst_new_camera(t_rt *rt, t_obj *objs, int title);
t_obj				*lst_new_light(t_rt *rt, t_obj *objs, int title);
t_obj				*lst_new_object(t_rt *rt, t_obj *objs, int title, int type);

/*
** ---------------------------- Handle Errors ----------------------------------
*/

void				init_errors(t_rt *r, int i);
int					error(t_rt *rt, int t);

/*
** --------------------------- Handle Info Bar ---------------------------------
*/

void				init_informations(t_rt *r, int i);

/*
** ---------------------------- Handle Shaders ---------------------------------
*/

char				*get_shader_name(t_obj *obj);

/*
** -----------------------------------------------------------------------------
** -------------------------------- Export -------------------------------------
** -----------------------------------------------------------------------------
*/

void				export_camera(t_obj *cam, int fd);
void				export_light(t_obj *light, int fd);
void				export_object(t_obj *obj, int fd);

void				export_config_file(t_rt *rt);

/*
** -----------------------------------------------------------------------------
** --------------------------------- Misc --------------------------------------
** -----------------------------------------------------------------------------
*/

int					free_elements(t_rt *rt);

/*
** -----------------------------------------------------------------------------
** ------------------------------- Clustering ----------------------------------
** -----------------------------------------------------------------------------
*/

int					cluster_init(t_cl *cl);
int					cluster_send_command(t_client *client, char command,
					void *arg, size_t arg_size);
int					cluster_send_command_all(t_cl *cl, char command,
					void *arg, size_t arg_size);
void				cluster_strategy(t_cl *cl);

#endif
