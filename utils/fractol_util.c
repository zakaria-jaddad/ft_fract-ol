/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:49:52 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/28 16:18:53 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <math.h>

int	mandelbrot(t_fractol *f, double real, double i, int iterations)
{

	double	tmp_real;
        f->z.i = f->z.real = 0;
	for (int iteration = 0; iteration < iterations; iteration++)
	{
		tmp_real = (f->z.real * f->z.real) - (f->z.i * f->z.i) + real;
		f->z.i = 2 * (f->z.real * f->z.i) + i;
		f->z.real = tmp_real;
		// Correct divergence check: If |z| > 2, return 0
		if ((f->z.real * f->z.real + f->z.i * f->z.i) > 4)

			return (iteration + 1 - log(2) / tan(tan(((real *real) + (i * i)))));
			/* return (iteration + 1 - (tan(((real *real) + (i * i)))) / log(2)); */
                 
			/* return (iteration + 1 - log(2) / tan(tan(((real *real) + (i * i))))); */
	}
	return (0);
}   


int	julia(t_fractol *f, double real, double i, int iterations)
{

	double	tmp_real;
	for (int iteration = 0; iteration < iterations; iteration++)
	{
		tmp_real = (real * real) - (i * i) + f->z.real;
		i = 2 * (real * i) + f->z.i;
		real = tmp_real;
		// Correct divergence check: If |z| > 2, return 0
		if ((real * real + i * i) > 4)
			/* return (iteration + 1 - log(2) / tan(((real *real) + (i * i)))); */
			return (iteration + 1 - log(2) / tan(tan(((real *real) + (i * i)))));
			/* return (iteration + 1 -  (tan(((real *real) + (i * i)))) / log(2)); */
			/* return (iteration + 1 -  (sqrt(tan(((real *real) + (i * i))))) / log(2)); */

	}
	return (0);
}

void draw_fractol(t_fractol *f)
{
        double real;
        double i;
        int color;

        for (long x = 0; x < WIDTH; x++)
        {
                for (long y = 0; y < HEIGHT; y++)
                {
                        /* real = (x - 320) * 0.00625 / f->view.zoom + f->view.center_x; */
                        /* i = -(y - 240) * 0.00625 / f->view.zoom + f->view.center_y; */
                        real = map(x, 0, WIDTH, -2, 2) / f->zoom.zoom + f->zoom.center_x;
                        i = -map(y, 0, HEIGHT, -2, 2) / f->zoom.zoom + f->zoom.center_y;
                        /* printf("%f\n", f->view.zoom); */
                        /* real = map(x, 0, WIDTH, -2, 2) / f->view.zoom; */
                        /* i = map(y, 0, HEIGHT, -2, 2) / f->view.zoom; */

                        color = f->fractol(f, real, i, ITERATION);
                        if (color != 0) 
                                my_pixel_put(&f->img, x, y, get_color(color) + f->color_index);
                        else 
                                my_pixel_put(&f->img, x, y, BLACK);
                }
        }
	mlx_put_image_to_window(f->mlx, f->mlx_window, f->img.img, 0, 0);
}


