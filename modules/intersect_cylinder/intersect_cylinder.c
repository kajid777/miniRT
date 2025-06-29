#include "../../miniRT.h"

double judge(double a, double b, double c)
{
	//Δ = B^2 - 4AC
	double result;
	
	result = pow(b, 2) - 4 * a * c;
	return (result);

}

double solve_quadratic(double a, double b, double c)
{
	// t = (-B ± √(B^2 - 4AC)) / (2A)
	double judgement = judge(a, b, c);
	double f_t = (-b + sqrt(judgement)) / (2 * a);
	double s_t = (-b - sqrt(judgement)) / (2 * a);

	if (f_t < s_t && f_t >= 0)
		return (f_t);
	else if (f_t > s_t && s_t >= 0)
		return (s_t);
	return (-1);
}

t_vec3 get_hitpoint(double t, t_vec3 d, t_vec3 origin)
{
	t_vec3 p;

	p = vec_add(origin, vec_mul_scalar(d, t));
	return (p);
}

t_vec3 intersect_cylinder(t_vec3 dir, t_vec3 origin, t_cylinder cylinder)
{
	//無限円柱との交点を考える
	t_vec3 d;
	t_vec3 o;
	t_vec3 w;
	double t;
	double d_parallel;
	double w_parallel;
	t_vec3 d_perp;
	t_vec3 w_perp;
	double a;
	double b;
	double c;

	d = dir;
	o = origin;
	//wは原点から円の中心までのベクトル
	w = vec_sub(origin, cylinder.center);
	//これをやるとrayの方程式を円柱中心を原点とした式になおせる
	//P = w + t * dir

	//円柱が垂直でない場合、単純にX軸Z軸成分を使うだけではダメ
	//軸方向成分の計算をする
	
	//d_parallel 光線が軸方向にどれだけ進むか
	d_parallel = vec_dot(d, cylinder.direction);
	//w_parallel 光線原点が軸方向にどの位置にある？
	//内積をとると、射影が出る
	//wの軸方向成分の大きさがわかる
	w_parallel = vec_dot(w, cylinder.direction);

	//垂直成分を求める
	d_perp = vec_sub(d, vec_mul_scalar(cylinder.direction, d_parallel));
	w_perp = vec_sub(w, vec_mul_scalar(cylinder.direction, w_parallel));

	//円柱表面の条件 |w_perp + t * d_perp| = radius
	//軸の並行成分を除去したから二次元の円の方程式でシンプルにいける
	a = vec_dot(d_perp, d_perp);                    // |d_perp|²
	b = 2.0 * vec_dot(w_perp, d_perp);              // 2(w_perp · d_perp)  
	c = vec_dot(w_perp, w_perp) - (cylinder.diameter / 2) * (cylinder.diameter / 2);  // |w_perp|² - radius²

	t = solve_quadratic(a, b, c);
	if (t < 0)
		return (vec_new(INFINITY, INFINITY, INFINITY));
	
	t_vec3 hitpoint = get_hitpoint(t, d, o);
	//高さのチェック
	//円柱の中心から交点の軸方向成分の長さが知りたい
	//中心からheight/2の長さなら範囲内
	t_vec3 from_center = vec_sub(hitpoint, cylinder.center);
	double height_axis = vec_dot(from_center, cylinder.direction);
	if (height_axis > cylinder.height / 2
		|| height_axis < -(cylinder.height / 2))
		return (vec_new(INFINITY, INFINITY, INFINITY));
	return (hitpoint);
}
