#include "../../miniRT.h"

t_vec3 intersect_plane(t_vec3 dir, t_vec3 origin, t_vec3 point, t_vec3 normal)
{
	t_vec3 d;
	t_vec3 n;
	t_vec3 p0;
	t_vec3 o;
	double t;
	
	d = dir;
	n = normal;
	p0 = point;
	o = origin;

	//(P - P0) ・N = 0
	//P = O + td

	//t = (O - P0) ・N / (D ・ N)
	t = vec_dot((vec_sub(o, p0)), n) / vec_dot(d, n);
	if (t == 0)
	{
		//カメラが物体の中
		return vec_new(INFINITY, INFINITY, INFINITY);
	}
	if (t < 0)
		return vec_new(INFINITY, INFINITY, INFINITY);
	return (get_hitpoint(t, d, o));
}

