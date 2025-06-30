#include "../../miniRT.h"

t_fcolor	color_new(double red, double blue, double green)
{
	t_fcolor	color;

	color.red = red;
	color.blue = blue;
	color.green = green;
	return (color);
}

t_fcolor	color_mul(t_fcolor c1, t_fcolor c2)
{
	return (color_new(c1.red * c2.red, c1.blue * c2.blue, c2.green * c2.green));
}

t_fcolor	color_mul_scalar(t_fcolor c, double scalar)
{
	return (color_new(c.red * scalar, c.blue * scalar, c.green * scalar));
}

t_fcolor	color_cal(double diffuse, t_fcolor color, t_fcolor ambient)
{
	t_fcolor	caluculated_color;

	caluculated_color = color_mul(color, ambient);
	caluculated_color = color_mul_scalar(caluculated_color, diffuse);
	return (caluculated_color);
}
