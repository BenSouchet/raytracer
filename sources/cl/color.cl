/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.cl                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodrigu <erodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:08:27 by erodrigu          #+#    #+#             */
/*   Updated: 2017/05/03 15:08:36 by erodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float3		calcul_clr(float3 ray, float3 normale, float3 light)
{
	float	cosinus;

	// ray = fast_normalize(ray);
	cosinus = dot(ray, normale);
	if (cosinus <= 0.0f)
		return(0);
	return((float3)(light * cosinus));
}

void		calcul_light(float3 *light_clr, global t_obj *obj)
{
	*light_clr -= (1.0f - obj->clr) * obj->opacity;
	if (light_clr->x < 0.0f)
		light_clr->x = 0.0f;
	if (light_clr->y < 0.0f)
		light_clr->y = 0.0f;
	if (light_clr->z < 0.0f)
		light_clr->z = 0.0f;
}

unsigned	calcul_rendu_light(t_data *data)
{

	float3	clr;

	if (data->rd_light.x > 1.0f)
		data->rd_light.x = 1.0f;
	if (data->rd_light.y > 1.0f)
		data->rd_light.y = 1.0f;
	if (data->rd_light.z > 1.0f)
		data->rd_light.z = 1.0f;
	clr =  data->rd_light * 255.0f;
	return ((((unsigned)clr.x & 0xff) << 24) + (((unsigned)clr.y & 0xff) << 16)
		+ (((unsigned)clr.z & 0xff) << 8) + ((unsigned)255 & 0xff));
}

float3	twocolor_lerp(float3 a, float3 b, float pc)
{
	float3 color;

	color.x = a.x * (1.0f - pc) + b.x * pc;
	color.y = a.y * (1.0f - pc) + b.y * pc;
	color.z = a.z * (1.0f - pc) + b.z * pc;
	return(color);
}
