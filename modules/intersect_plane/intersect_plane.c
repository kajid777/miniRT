#include "../../miniRT.h"

t_hit intersect_plane(t_vec3 dir, t_vec3 origin, t_vec3 point, t_vec3 normal, t_vec3 light_pos)
{

	double t;
	t_vec3	hp;	

	//(P - P0) ・N = 0
	//P = O + td

	//t = (O - P0) ・N / (D ・ N)
	t = vec_dot((vec_sub(origin, point)), normal) / vec_dot(dir, normal);
	if (t == 0)
	{
		//カメラが物体の中
		return new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), vec_new(0, 0, 0), -1, 1);
	}
	if (t < 0)
		return new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), vec_new(0, 0, 0), -1, 0);
	hp = get_hitpoint(t, dir, origin);
	return(new_hit(hp, normal, get_light_dir(hp, light_pos), t, 1));
}

