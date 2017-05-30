double smooth_noise_1d(float3 pos)
{
	int3 integer;
	double3 fractional;

	integer.x = (int)pos.x;
	integer.y = (int)pos.y;
	if (pos.x < 0)
		integer.x = (int)pos.x - 1;
	if (pos.y < 0)
		integer.y = (int)pos.y - 1;
	fractional.x = (double)pos.x - integer.x;
	double a0 = rand_noise(integer.x);
	double a1 = rand_noise(integer.x + integer.y);
	return(cosine_interpolate(a0, a1, fractional.x));
}
