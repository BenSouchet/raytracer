float3			rotate_ray(t_data *data, short *index)
{
	float3	res;
	float3	rad;
	float3	matx;
	float3	maty;
	float3	matz;	
	float3	ray;

	ray = (float3){0.0f, 1.0f, 0.0f};
	rad = data->objs[(int)*index].rot * ((float)M_PI / 180.0f);
	matx = (float3){native_cos(rad.y) * native_cos(rad.z),
	native_cos(rad.y) * (-native_sin(rad.z)),
	native_sin(rad.y)};
	maty = (float3){(-native_sin(rad.x)) * (-native_sin(rad.y)) *
	native_cos(rad.z) + native_cos(rad.x) * native_sin(rad.z),
	(-native_sin(rad.x)) * (-native_sin(rad.y)) * (-native_sin(rad.z)) +
	native_cos(rad.x) * native_cos(rad.z), (-native_sin(rad.x)) *
	native_cos(rad.y)};
	matz = (float3){native_cos(rad.x) * (-native_sin(rad.y)) *
	native_cos(rad.z) + native_sin(rad.x) * native_sin(rad.z),
	native_cos(rad.x) * (-native_sin(rad.y)) * (-native_sin(rad.z)) +
	native_sin(rad.x) * native_cos(rad.z), native_cos(rad.x) *
	native_cos(rad.y)};
	res.x = dot(matx, ray);
	res.y = dot(maty, ray);
	res.z = dot(matz, ray);
	return(res);
}

float3			rotate_cam(float3 rot)
{
	float3	res;
	float3	rad;
	float3	matx;
	float3	maty;
	float3	matz;
	float3	ray;

	ray = (float3){0.0f, 0.0f, 1.0f};
	rad = rot * ((float)M_PI / 180.0f);
	matx = (float3){native_cos(rad.y) * native_cos(rad.z),
	native_cos(rad.y) * (-native_sin(rad.z)),
	native_sin(rad.y)};
	maty = (float3){(-native_sin(rad.x)) * (-native_sin(rad.y)) *
	native_cos(rad.z) + native_cos(rad.x) * native_sin(rad.z),
	(-native_sin(rad.x)) * (-native_sin(rad.y)) * (-native_sin(rad.z)) +
	native_cos(rad.x) * native_cos(rad.z), (-native_sin(rad.x)) *
	native_cos(rad.y)};
	matz = (float3){native_cos(rad.x) * (-native_sin(rad.y)) *
	native_cos(rad.z) + native_sin(rad.x) * native_sin(rad.z),
	native_cos(rad.x) * (-native_sin(rad.y)) * (-native_sin(rad.z)) +
	native_sin(rad.x) * native_cos(rad.z), native_cos(rad.x) *
	native_cos(rad.y)};
	matx = (float3){cos(rad.y) * cos(rad.z),
	cos(rad.y) * (-sin(rad.z)),
	sin(rad.y)};
	maty = (float3){(-sin(rad.x)) * (-sin(rad.y)) * cos(rad.z) +
	cos(rad.x) * sin(rad.z), (-sin(rad.x)) * (-sin(rad.y)) * (-sin(rad.z)) +
	cos(rad.x) * cos(rad.z), (-sin(rad.x)) * cos(rad.y)};
	matz = (float3){cos(rad.x) * (-sin(rad.y)) * cos(rad.z) + sin(rad.x) *
	sin(rad.z), cos(rad.x) * (-sin(rad.y)) * (-sin(rad.z)) + sin(rad.x) *
	cos(rad.z), cos(rad.x) * cos(rad.y)};
	res.x = dot(matx, ray);
	res.y = dot(maty, ray);
	res.z = dot(matz, ray);
	return(res);
}