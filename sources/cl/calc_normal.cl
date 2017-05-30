static float3        plane_normal(t_data *data, float3 rot)
{
	if (dot(data->ray_dir, rot) > 0.0f)
        return (-rot);
    return (rot);
}

static float3        cone_normal(t_data *data, float3 rot)
{
    float   m;
    float   k;

    m = dot(data->ray_dir, rot * data->t) + dot(rot, data->ray_pos -
        data->objs[data->id].pos);
    k = tan((data->objs[data->id].radius / 2.0f) * (float)(M_PI / 180.0f));
    return (data->intersect - data->objs[data->id].pos - ((1.0f + k * k) *
    rot * m));
}

static float3       cylinder_normal(t_data *data, float3 rot)
{
    float   m;

	m = dot(data->ray_dir, rot * data->t) + dot(rot, data->ray_pos -
        data->objs[data->id].pos);
    return (data->intersect - data->objs[data->id].pos - rot * m);
}

static float3       sphere_normal(t_data *data)
{
    return (data->intersect - data->objs[data->id].pos);
}

float3		        calcul_normale(t_data *data)
{
    float3      rot;
    float3      normale;

    rot = rotate_ray(data, &data->id);
    if (data->objs[data->id].type == T_PLANE ||
     ((data->objs[data->id].type == T_CONE ||
    data->objs[data->id].type == T_CYLINDER) && data->type == T_DISK))
        normale = plane_normal(data, rot);
    else if (data->objs[data->id].type == T_CONE)
        normale = cone_normal(data, rot);
    else if (data->objs[data->id].type == T_CYLINDER)
        normale = cylinder_normal(data, rot);
	else if (data->objs[data->id].type == T_SPHERE)
        normale = sphere_normal(data);
    else
        normale = 0.0f;
    return (fast_normalize(normale));
}
