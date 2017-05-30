/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_intersect.cl                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:11:30 by lgatibel          #+#    #+#             */
/*   Updated: 2017/02/13 11:11:39 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 			set_offset(t_data *data, short *index)
{
	data->offset = data->ray_pos - data->objs[(int)*index].pos;
}

void			calc_intersect(t_data *data)
{
	data->intersect = data->ray_pos + (data->ray_dir * data->t);
}

short			plane_intersection(t_data *data, short *index)
{
	float3	rot;
	float	div;

	rot = rotate_ray(data, index);
	set_offset(data, index);
	div = dot(data->ray_dir, rot);
	if (div == 0.0f)
		return (0);
	data->t = (-dot(data->offset, rot)) / div;
	if (data->t < 0.0f)
		return (0);
	calc_intersect(data);
	return (1);
}

short			cone_intersection(t_data *data, short *index)
{
	float3	disc;
	float3	rot;
	float	m;
	float	tanj;
	float	k;

	k = tan((data->objs[(int)*index].radius / 2.0f) * (float)(M_PI / 180.0f));
	tanj = 1.0f + pow(k, 2);
	rot = rotate_ray(data, index);
	set_offset(data, index);
	disc.x = dot(data->ray_dir, data->ray_dir) - (tanj *
	pow(dot(data->ray_dir, rot), 2));
	disc.y = dot(data->ray_dir, data->offset) - (tanj *
		(dot(data->ray_dir, rot) * dot(data->offset, rot)));
	disc.z = dot(data->offset, data->offset) - (tanj *
	pow(dot(data->offset, rot), 2));
	if (calc_delta(&disc, data) == -1)
	{
		m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
		if (data->objs[(int)*index].height > 0.0f)
		{
			m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
			if (m < 0.0f || m > data->objs[(int)*index].height)
		 		return (cone_caps(data, &rot, index, m));
		}
		return (0);
	}
	if (data->objs[(int)*index].height > 0.0f)
	{ 
		m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
		if (m < 0.0f)
			data->t = data->t0 > data->t1 ? data->t0 : data->t1;
		m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
		if (m < 0.0f || m > data->objs[(int)*index].height)
	 		return (cone_caps(data, &rot, index, m));
	}
	calc_intersect(data);
	return (1);
}

short			cylinder_intersection(t_data *data, short *index)
{
	float3	disc;
	float3	rot;
	float	m;

	rot = rotate_ray(data, index);
	set_offset(data, index);
	disc.x = dot(data->ray_dir, data->ray_dir) -
		dot(data->ray_dir, rot) * dot(data->ray_dir, rot);
	disc.y = dot(data->ray_dir, data->offset) -
		dot(data->ray_dir, rot) * dot(data->offset, rot);
	disc.z = dot(data->offset, data->offset) -
		dot(data->offset, rot) * dot(data->offset, rot) -
		data->objs[(int)*index].radius * data->objs[(int)*index].radius;
	if (calc_delta(&disc, data) == -1)
	{
		if (data->objs[(int)*index].height > 0.0f)
		{
			m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
			if (m < 0.0f || m > data->objs[(int)*index].height)
				return (cylinder_caps(data, &rot, index, m));
		}
		return (0);
	}
	if (data->objs[(int)*index].height > 0.0f)
	{
		m = dot(data->ray_dir, rot * data->t) + dot(rot, data->offset);
		if (m < 0.0f || m > data->objs[(int)*index].height)
			return (cylinder_caps(data, &rot, index, m));
	}
	calc_intersect(data);
	return (1);
}

short			sphere_intersection(t_data *data, short *index)
{
	float3	disc;

	set_offset(data, index);
	disc.x = dot(data->ray_dir, data->ray_dir);
	disc.y = dot(data->ray_dir, data->offset);
	disc.z = dot(data->offset, data->offset) -
	data->objs[(int)*index].radius * data->objs[(int)*index].radius;
	if (calc_delta(&disc, data) == -1)
		return (0);
	calc_intersect(data);
	return (1);
}
