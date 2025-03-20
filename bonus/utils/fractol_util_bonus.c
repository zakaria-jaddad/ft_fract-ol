/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:49:52 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 00:00:57 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"
#include <math.h>
#include <stdio.h>

int	clean(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->mlx_window);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	f->mlx = NULL;
	f->mlx_window = NULL;
	f->mlx_window = NULL;
	f->img.img = NULL;
	f->img.addr = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

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
			return (iteration);
		iteration++;
	}
	return (iteration);
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
		iteration++;
		if ((real * real + i * i) > 4)
			return (iteration);
	}
	return (iteration);
}


int     burning_ship(t_fractol *f, double real, double i, int iterations)
{
	double	tmp_real;
	int		iteration;

	iteration = 0;
	while (iteration < iterations)
	{
		tmp_real = (real * real) - (i * i) + f->z.real;
		i = abs((int)(2 * real * i)) + f->z.i;
		real = tmp_real;
		iteration++;
		if ((real * real + i * i) > 4)
			return (iteration);
	}
	return (iteration);
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
                        real = map(x, 0, WIDTH) / f->view.zoom + f->view.center_x;
                        i = -map(y, 0, HEIGHT) / f->view.zoom + f->view.center_y;
			color = f->fractol(f, real, i, ITERATION);
			if (color == ITERATION)
				my_pixel_put(&f->img, x, y, BLACK);
			else
				my_pixel_put(&f->img, x, y, get_color(color) + f->color_shift);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->mlx_window, f->img.img, 0, 0);
}
