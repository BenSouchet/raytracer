static float3		reflex_is_light(t_data *data, float3 lightdir,
	global t_lgt *lgt)
{
	float3	light_clr;

	data->ray_pos = lgt->pos;
	data->ray_dir = lightdir;
	touch_object(data);
	if ((data->id == data->save_id &&
		fast_distance(data->save_inter, lgt->pos) <
		fast_distance(data->intersect, lgt->pos) + PREC))
	{
		data->nl++;
		light_clr = calcul_clr(-lightdir, data->normale, lgt->clr *
			data->clr);
		if (data->objs[data->id].specular)
			light_clr += is_shining(data->normale, -lightdir, lgt->clr);
		return (light_clr);
	}
	if (fast_distance(data->save_inter, data->save_pos) <
	fast_distance(data->intersect, data->save_pos) + PREC)
		data->test++;
	return (0);
}

static float3		reflex_check_all_light(t_data *data)
{
	short	i;
	float3	lightdir;
	float3	rd_light;

	i = -1;
	rd_light = 0.0f;
	data->clr = get_obj_color(data);
	if (data->skytype)
		return (get_font_color(data, &data->light_reflex_pow));
	while (++i < data->n_lgts)
	{
		lightdir = fast_normalize(data->intersect - data->lights[i].pos);
		rd_light += reflex_is_light(data, lightdir, &data->lights[i]);
	}
	rd_light += calcul_clr(data->ray_dir, -data->normale,
	AMBIANT * data->clr);
	if (!data->nl || data->test >= data->n_lgts)
	 	return (rd_light);
	else if (data->n_lgts == 1 || (data->n_lgts - data->test == 1))
		return (rd_light / (1.0f + AMBIANT) * data->light_reflex_pow);
	return (rd_light  / (data->n_lgts - data->test + AMBIANT) *
	 data->light_reflex_pow);
}

void	calcul_reflex_ray(t_data *data)
{
	data->reflex++;
	data->test = 0;
	data->nl = 0;
	data->light_reflex_pow = data->light_pow -
	 (1.0f - data->objs[data->save_id].reflex);
	data->light_pow -= data->objs[data->save_id].reflex;
	if (data->light_reflex_pow >= 0.0f)
	{
	data->normale = calcul_normale(data);
	data->ray_pos = data->intersect - PREC * data->ray_dir;
	data->ray_dir = fast_normalize(data->ray_dir - (2.0f * data->normale *
	dot(data->normale, data->ray_dir)));
	touch_object(data);
	data->normale = calcul_normale(data);
	data->rd_light += reflex_check_all_light(data);
	load(data);
	}
}
