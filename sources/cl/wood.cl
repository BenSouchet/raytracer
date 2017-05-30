#include "noise.h"

float3	wood_shaders(float3 pos)
{
	double		v;
	t_shader	colors;

	colors.col1 = (float3){82.2f, 40.4f, 4.5f};
	colors.col2 = (float3){102.0f, 51.0f, 5.0f};
	colors.col3 = (float3){146.0f, 85.f, 15.0f};
	colors.col1 /= 255.0f;
	colors.col2 /= 255.0f;
	colors.col3 /= 255.0f;
	v = 20 * perlin(OCTAVE, FREQUENCY, PERSIS, pos / 15.0f);
	v = v - (int)v;
	return (lerp_wood(v, colors));
}

float3	lerp_wood(float v, t_shader colors)
{
	float	v1 = -1.0f;
	float	v2 = -0.50f;
	float	v3 = 0.5f;
	float	v4 = 1.0f;
	if (v >= v1 && v < v2)
		return ((colors.col2 * (v - v1) / (v2 - v1) + colors.col3 * (v2 - v) / (v2 - v1)));
	else if (v >= v2 && v < v3)
		return ((colors.col3 * (v - v2) / (v3 - v2) + colors.col2 * (v3 - v) / (v3 - v2)));
	return ((colors.col2 * (v - v3) / (v4 - v3) + colors.col1 * (v4 - v) / (v4 - v3)));
}
