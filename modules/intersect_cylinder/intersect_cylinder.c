#include "../../miniRT.h"

typedef struct s_cylinder{
	t_vec3 center;
	t_vec3 orientation;
	double radius;
	double height;
}

t_vec3 intersect_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder cylinder)
{
	//まず無限円柱との交差を考える
	//|| (P - C) - [(O - C)・V] V || = r
	//P = O + td
	// 

}

