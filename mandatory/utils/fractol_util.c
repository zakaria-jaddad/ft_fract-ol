/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:49:52 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/14 00:47:09 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_fractol *f, double real, double i, int iterations)
{
	double	tmp_real;
	int		iteration;

	(void)!(f->z.i = f->z.real = 0, 0);
	iteration = 0;
	while (iteration < iterations)
	{
		tmp_real = (f->z.real * f->z.real) - (f->z.i * f->z.i) + real;
		f->z.i = 2 * (f->z.real * f->z.i) + i;
		f->z.real = tmp_real;
		if ((f->z.real * f->z.real + f->z.i * f->z.i) > 4)
			return (iteration + 1 - log(2) / tan(tan(((real * real) + (i
								* i)))));
		iteration++;
	}
	return (0);
}

int	julia(t_fractol *f, double real, double i, int iterations)
{
	double	tmp_real;
	int		iteration;

	iteration = 0;
	while (iteration < iterations)
	{
		tmp_real = (real * real) - (i * i) + f->z.real;
		i = 2 * (real * i) + f->z.i;
		real = tmp_real;
		if ((real * real + i * i) > 4)
			return (iteration + 1 - log(2) / tan(tan(((real * real) + (i
								* i)))));
		iteration++;
	}
	return (0);
}

void	draw_fractol(t_fractol *f)
{
	double	real;
	double	i;
	int		color;
	long	x;
	long	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			real = map(x, 0, WIDTH) / f->zoom;
			i = -map(y, 0, HEIGHT) / f->zoom;
			color = f->fractol(f, real, i, ITERATION);
			if (color != 0)
				my_pixel_put(&f->img, x, y, get_color(color) + f->color_index);
			else
				my_pixel_put(&f->img, x, y, BLACK);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_window, f->img.img, 0, 0);
}
