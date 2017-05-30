/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 11:16:13 by lgatibel          #+#    #+#             */
/*   Updated: 2017/04/27 11:16:20 by lgatibel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short       cone_caps(t_data *data, float3 *rot, short *index, float m)
{
    float   radius;
    float	div;

    if (m > data->objs[(int)*index].height)
    {
        data->pos = data->objs[(int)*index].pos + *rot *
        data->objs[(int)*index].height;
    }
    else if (m < 0.0f)
		return (0);
    data->offset = data->ray_pos - data->pos;
    div = dot(*rot, data->ray_dir);
    if (div == 0.0f)
        return (0);
    data->t = (-dot(*rot, data->offset)) / div;
    if (data->t < 0.0f)
        return (0);
    calc_intersect(data);
    radius = tan((data->objs[(int)*index].radius / 2.0f) *
    (float)(M_PI / 180.0f)) * data->objs[(int)*index].height;
    if (radius + PREC < distance(data->intersect, data->pos))
        return (0);
    data->type = T_DISK;
    return (1);
}

short       cylinder_caps(t_data *data, float3 *rot, short *index, float m)
{
    float	div;

    if (m < 0.0f)
        data->pos = data->objs[(int)*index].pos;
    else
    {
        data->pos = data->objs[(int)*index].pos + *rot *
            data->objs[(int)*index].height;
        data->offset = data->ray_pos - data->pos;
    }
    div = dot(*rot, data->ray_dir);
    if (div == 0.0f)
        return (0);
    data->t = (-dot(*rot, data->offset)) / div;
    if (data->t < 0.0f)
        return (0);
    calc_intersect(data);
    if (fast_distance(data->intersect, data->pos) >
    data->objs[(int)*index].radius)
        return (0);
    data->type = T_DISK;
    return (1);
}
