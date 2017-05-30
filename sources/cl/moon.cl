#include "noise.h"

float3	moon_shaders(float3 pos)
{
	double		v;
	t_shader	colors;

	colors.col1 = (float3){210.0f, 210.0f, 210.0f};
	colors.col2 = (float3){155.0f, 155.0f, 155.0f};
	colors.col3 = (float3){105.0f, 105.0f, 105.0f};
	colors.col1 /= 255.0f;
	colors.col2 /= 255.0f;
	colors.col3 /= 255.0f;
	v = perlin(OCTAVE, FREQUENCY, PERSIS, pos * 5.0f);
	v = v - (int)v;
	return (earth_lerp(v, colors));
}

float3	moon_lerp(float v, t_shader colors)
{
	float	v1 = -1.0f;
	float	v2 = -0.5f;
	float	v3 = 0.5f;
	float	v4 = 1.0f;
	if (v >= v1 && v < v2)
		return ((colors.col2 * (v - v1) / (v2 - v1) + colors.col1 * (v2 - v) / (v2 - v1)));
	else if (v >= v2 && v < v3)
		return ((colors.col3 * (v - v2) / (v3 - v2) + colors.col2 * (v3 - v) / (v3 - v2)));
	return ((colors.col2 * (v - v3) / (v4 - v3) + colors.col3 * (v4 - v) / (v4 - v3)));
}
