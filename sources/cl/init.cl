/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.cl                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:17:15 by lgatibel          #+#    #+#             */
/*   Updated: 2017/05/10 10:45:12 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		init_data(t_data *data, global t_obj *objs,
global t_lgt *lgts, short n_objs, short n_lgts, float3 ray_pos,
float3 ray_dir, global unsigned int *pixel, short skytype)
{
	data->ray_pos = ray_pos;
	data->ray_dir = ray_dir;
	data->intersect = 0.0f;
	data->save_pos = 0.0f;
	data->save_dir = 0.0f;
	data->save_inter = 0.0f;
	data->save_clr = 0.0f;
	data->save_id = 0;
	data->save_t = 0;
	data->through = -1;
	data->test = 0;
	data->inter = 0.0f;
	data->light_pow = 1.0f;
	data->light_refract_pow = 0.0f;
	data->light_reflex_pow = 1.0f;
	data->id = -1;
	data->reflex = 0;
	data->opacity = 0;
	data->skytype = skytype;
	data->type = -1;
	data->rd_light = 0.0f;
	data->pos = 0;
	data->inter = 0.0f;
	data->clr = 0.0f;
	data->offset = 0.0f;
	data->normale = 0;
	data->is_light = 0;
	data->nl = 0;
	data->t = 0.0f;
	data->t0 = 0.0f;
	data->t1 = 0.0f;
	data->objs = objs;
	data->lights = lgts;
	data->pixel = pixel;
	data->n_objs = n_objs;
	data->n_lgts = n_lgts;
}
