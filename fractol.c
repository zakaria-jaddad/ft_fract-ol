/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/20 23:49:51 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
#include "mlx/mlx.h"
#include <math.h>
#include <stdio.h>


/*
 * TODO: 
 * - creat a window
 * - add an image in the window
 * - add a white image in the window
 * - draw a fractal based on an suit
 */

// struct to hold information about image
typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

// real is x axies
// i is imaginary axies
typedef struct s_complex {
        double real;
        double i;
} t_complex;

// macros
#define HEIGHT 600
#define WIDTH  800
#define SCALE 0.1;
#define ITERATION 250

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

        // calculate the position of the (x, y) pixle and return it
        // since char is 1 byte that's why it's used
        // color is just and integer 0xFFFFFF00 representation if Alpha, red, green and blue
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* Mandelbrot_set */
// (a * a) + (a * bi) + (a* bi) + (bi * bi) → (a * a) — (b * b) + 2 * (a * bi).


/* check weather a point diverge or not */
int ispoint_diverge(double real, double i, int iterations)
{
    t_complex z;
    z.real = 0;
    z.i = 0;

    for (int iteration = 0; iteration < iterations; iteration++) {
        double tmp_real = (z.real * z.real) - (z.i * z.i) + real;
        z.i = 2 * (z.real * z.i) + i;
        z.real = tmp_real;

        // Correct divergence check: If |z| > 2, return 0
        if ((z.real * z.real + z.i * z.i) > 4)
            return 0;
    }
    return 1;
}


double map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/*
 * ./fractol mandelbrot 
 * ./fractol julia <real> <i>
 */
int main(void)
{
        void *mlx;
        void *mlx_window;
        t_img img;

        mlx = mlx_init();


        mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");


        img.img = mlx_new_image(mlx, WIDTH, HEIGHT);


        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);



        for (long x = 0; x < WIDTH; x++) {
                for (long y = 0; y < HEIGHT; y++) {
                        double real = map(x, 0, WIDTH, -2, 2);
                        double i = map(y, 0, HEIGHT, -2, 2);

                        if (ispoint_diverge(real, i, ITERATION))
                                my_pixel_put(&img, x, y, 0xFFFFFFFF);
                }
        }
        mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);

        mlx_loop(mlx);
        (void)mlx_window;
        (void)img;
        return EXIT_SUCCESS;
}
