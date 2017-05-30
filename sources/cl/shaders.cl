#include "noise.cl"
#include "wood.cl"
#include "marbre.cl"
#include "noise_1d.cl"
#include "earth_shader.cl"
#include "moon.cl"
#include "noise.h"

float3	get_shaders(float3 pos, int shader, float3 col)
{
	if (shader == WOOD)
		return (wood_shaders(pos));
	if (shader == STAR)
		return (twocolor_lerp((float3){240.0/255, 10.0/255, 10.0/255},
		(float3){255.0 / 255, 204.0 / 255, 40.0/255}, perlin(OCTAVE, FREQUENCY, PERSIS, pos)));
	if (shader >= MARBRE1 && shader <= MARBRE7)
		return (marbre_shaders(pos, shader, col));
	if (shader == SKYSTAR)
		return (moon_shaders(pos));
	if (shader == SKYDAY)
		return (earth_shaders(pos));
	return (0);
}

float3	get_font(float3 pos)
{
	double	v;

	v = smooth_noise_1d(pos * 1000000);
	if (v <= 1.0 && v > 0.995)
		return ((float3){1.0f, 1.0f, 0.8f});
	if (v <= 0.995 && v > 0.99)
		return ((float3){0.85f, 0.35f, 0.0f});
	if (v <= 0.99 && v > 0.985)
		return ((float3){0.55f, 0.72f, 1.0f});
	return((float3){0.0, 0.0, 0.0});
}
