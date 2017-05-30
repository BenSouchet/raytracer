/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erodrigu <erodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 16:38:12 by erodrigu          #+#    #+#             */
/*   Updated: 2017/05/12 16:15:18 by erodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOISE_H
# define NOISE_H
# define OCTAVE 12
# define FREQUENCY 0.125
# define PERSIS 0.5

typedef struct	s_shader
{
	float3		col1;
	float3		col2;
	float3		col3;
}				t_shader;

void			set_color_marbre(float3 obj_col, t_shader *colors);
float3			get_font(float3 pos);
float3			choose_color(int color);
float3			moon_shaders(float3 pos);
float3			wood_shaders(float3 pos);
float3			earth_shaders(float3 pos);
float3			get_font_night(float3 pos);
float3			moon_lerp(float v, t_shader colors);
float3			lerp_wood(float v, t_shader colors);
float3			earth_lerp(float v, t_shader colors);
float3			get_shaders(float3 pos, int shader, float3 col);
float3			marbre_shaders(float3 pos, int shader, float3 obj_col);
double			rand_noise(int t);
double			smooth_noise_1d(float3 pos);
double			smooth_noise_3d(float3 pos);
double			noise_3d(int x, int y, int z);
double			cosine_interpolate(double a, double b, double t);
double			perlin(int octaves, float frequency, double persistence,
	float3 pos);
#endif
