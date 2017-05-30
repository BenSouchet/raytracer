#include "noise.h"

float3	earth_shaders(float3 pos)
{
	double		v;
	t_shader	colors;

	colors.col1 = (float3){42.2f, 74.4f, 179.0f};
	colors.col2 = (float3){34.0f, 129.0f, 24.0f};
	colors.col3 = (float3){135.0f, 66.f, 8.0f};
	colors.col1 /= 255.0f;
	colors.col2 /= 255.0f;
	colors.col3 /= 255.0f;
	v = perlin(OCTAVE, FREQUENCY, PERSIS, pos / 1.0f);
	v = v - (int)v;
	return (earth_lerp(v, colors));
}

float3	earth_lerp(float v, t_shader colors)
{
	float	v1 = 0.50f;
	float	v2 = 0.75f;
	float	v3 = 0.875f;
	float	v4 = 1.0f;
	if (v >= -1.0f && v < 0.5f)
		return (colors.col1);
	if (v >= v1 && v < v2)
		return ((colors.col1 * (v - v1) / (v2 - v1) + colors.col2 * (v2 - v)
		/ (v2 - v1)));
	else if (v >= v2 && v < v3)
		return ((colors.col3 * (v - v2) / (v3 - v2) + colors.col2 * (v3 - v)
		/ (v3 - v2)));
	return ((colors.col2 * (v - v3) / (v4 - v3) + colors.col3 * (v4 - v)
		/ (v4 - v3)));
}
