#include "../includes/miniRT.h"

double	judge(double a, double b, double c)
{
	double	result;

	result = pow(b, 2) - 4 * a * c;
	return (result);
}

double	solve_quadratic(double a, double b, double c)
{
	double	discriminant;
	double	t1;
	double	t2;
	double	sqrt_disc;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	if (t1 > 0.001)
		return (t1);
	else if (t2 > 0.001)
		return (t2);
	return (-1);
}

static void	swap_if_needed(double *t1, double *t2)
{
	double	temp;

	if (*t1 > *t2)
	{
		temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
}

static void	set_quadratic_results(double sqrt_disc, double a, double b,
		double *t1, double *t2)
{
	*t1 = (-b - sqrt_disc) / (2 * a);
	*t2 = (-b + sqrt_disc) / (2 * a);
	swap_if_needed(t1, t2);
}

int	solve_quadratic_both(double a, double b, double c, double *results)
{
	double	discriminant;
	double	sqrt_disc;

	discriminant = judge(a, b, c);
	if (discriminant < 0)
		return (0);
	if (discriminant == 0)
	{
		results[0] = results[1] = -b / (2 * a);
		return (1);
	}
	sqrt_disc = sqrt(discriminant);
	set_quadratic_results(sqrt_disc, a, b, &results[0], &results[1]);
	return (2);
}

t_vec3	get_norm_sphere(t_vec3 hitpoint, t_vec3 center)
{
	t_vec3	norm;

	norm = vec_sub(hitpoint, center);
	norm = vec_norm(norm);
	return (norm);
}
