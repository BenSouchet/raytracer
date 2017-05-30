#include "noise.h"

float3	marbre_shaders(float3 pos, int shader, float3 obj_col)
{
	double		v;
	t_shader	colors;

	set_color_marbre(obj_col, &colors);
	if (shader == MARBRE1)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.x);
	else if (shader == MARBRE2)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.y);
	else if (shader == MARBRE3)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.z);
	else if (shader == MARBRE4)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.x + pos.y);
	else if (shader == MARBRE5)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.x + pos.z);
	else if (shader == MARBRE6)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.y + pos.z);
	else if (shader == MARBRE7)
		v = cos(perlin(OCTAVE, FREQUENCY, PERSIS, pos) + pos.x + pos.y + pos.z);
	return (lerp_wood(v, colors));
}

void	set_color_marbre(float3 obj_col, t_shader *colors)
{
	int3 obj_int_color;

	obj_int_color.x = ((int)(obj_col.x * 255.0f)) % 10;
	obj_int_color.y = ((int)(obj_col.y * 255.0f)) % 10;
	obj_int_color.z = ((int)(obj_col.z * 255.0f)) % 10;
	colors->col1 = choose_color(obj_int_color.x) / 255.0f;
	colors->col2 = choose_color(obj_int_color.y) / 255.0f;
	colors->col3 = choose_color(obj_int_color.z) / 255.0f;
}

float3	choose_color(int color)
{
	if (color == 1)
		return ((float3){255.0f, 0.0f, 0.0f});
	if (color == 2)
		return ((float3){0.0f, 255.0f, 0.0f});
	if (color == 3)
		return ((float3){0.0f, 0.0f, 255.0f});
	if (color == 4)
		return ((float3){165.0f, 75.0f, 38.0f});
	if (color == 5)
		return ((float3){240.0f, 240.0f, 5.0f});
	if (color == 6)
		return ((float3){240.0f, 5.0f, 240.0f});
	if (color == 7)
		return ((float3){39.0f, 163.0f, 176.0f});
	if (color == 8)
		return ((float3){0.0f, 0.0f, 0.0f});
	if (color == 9)
		return ((float3){105.0f, 105.0f, 105.0f});
	if (color == 0)
		return ((float3){255.0f, 255.0f, 255.0f});
	return (0);
}
