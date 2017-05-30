#include "noise.h"

/* fonction qui renvois un nombre pseudo aleatoire entre 0 et 1 */

double rand_noise(int t)
{
    t = (t<<13) ^ t;
    t = (t * (t * t * 15731 + 789221) + 1376312589);
    return ((t & 0x7fffffff) / 1073741824.0);
}

/* prend 3 int pour revoyer un double entre 0 et 1 */

double noise_3d(int x, int y, int z)
{
	int		tmp1;
	int		tmp2;
    tmp1 = rand_noise(x) * 850000;
    tmp2 = rand_noise(tmp1 + y) * 850000;
    return(rand_noise(tmp2 + z));
}

/* relie les points de facon cosinusoidale et de facon continue */

double cosine_interpolate(double a, double b, double t)
{
    double	c;

	c = (1 - cos(t * 3.1415927)) * .5;
    return (1. - c) * a + c * b;
}

/* prend une position et renvois un nombre entre 0 et 1 */

double smooth_noise_3d(float3 pos)
{
	int3 integer;
	double3 fractional;
	double3	face_up;
	double3	face_down;

	integer.x = (int)pos.x;
	integer.y = (int)pos.y;
	integer.z = (int)pos.z;
	if (pos.x < 0)
		integer.x = (int)pos.x - 1;
	if (pos.y < 0)
		integer.y = (int)pos.y - 1;
	if (pos.z < 0)
		integer.z = (int)pos.z - 1;

	fractional.x = (double)pos.x - integer.x;
	fractional.y = (double)pos.y - integer.y;
	fractional.z = (double)pos.z - integer.z;

	double a0 = noise_3d(integer.x, integer.y, integer.z);
	double a1 = noise_3d(integer.x + 1, integer.y, integer.z);

	double b0 = noise_3d(integer.x, integer.y + 1, integer.z);
	double b1 = noise_3d(integer.x + 1, integer.y + 1, integer.z);

	double c0 = noise_3d(integer.x, integer.y, integer.z + 1);
	double c1 = noise_3d(integer.x + 1, integer.y, integer.z + 1);

	double d0 = noise_3d(integer.x, integer.y + 1, integer.z + 1);
	double d1 = noise_3d(integer.x + 1, integer.y + 1, integer.z + 1);

	face_up.x = cosine_interpolate(a0, a1, fractional.x);
	face_up.y = cosine_interpolate(b0, b1, fractional.x);
	face_up.z = cosine_interpolate(face_up.x, face_up.y, fractional.y);

	face_down.x = cosine_interpolate(c0, c1, fractional.x);
	face_down.y = cosine_interpolate(d0, d1, fractional.x);
	face_down.z = cosine_interpolate(face_down.x, face_down.y, fractional.y);

	return cosine_interpolate(face_up.z, face_down.z, fractional.z);
}

/* ajoute de la coherence au bruit */

double perlin(int octaves, float frequency, double persistence, float3 pos)
{
    double	r = 0.0;
    float	amplitude = 1.0f;
	int		i = 0;
	int		t;

    while(i < octaves)
    {
        t = i * 4096;
        r += smooth_noise_3d(pos * frequency) * amplitude;
        amplitude *= persistence;
        frequency *= 2.0;
		i++;
    }
    return(r * ((1 - persistence) / (1 - amplitude)));
}
