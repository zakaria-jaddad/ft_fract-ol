/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/20 22:50:38 by zajaddad         ###   ########.fr       */
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
        z.real = z.i = 0;

        for (int iteration = 0; iteration < iterations; iteration++) {
                double tmp_real;

                tmp_real = (z.real * z.real) - (z.i * z.i);
                z.i = 2 * (z.real * z.i);
                z.real = tmp_real;

                // add point c
                z.real += real;
                z.i += i;
                if ((z.real < -2 && z.real > 2) || (z.i < -2 && z.i > 2))
                        return 0;
        }
        return 1;
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

        /*
         * // initialize an mlx window
         * mlx_init: establish a connection to the correct graphical system and return void *
         * which holds the location of the current MLX instance
         */
        mlx = mlx_init();

        /*
         * // creat window using mlx
         * mlx_new_window: creat a new windw and return a pointer to it
         * mlx_loop: to initialize the windw redering
         */
        mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");

        /*
         * mlx_new_image: initialize an image and put it in the mlx window
         * returns the image address
         */
        img.img = mlx_new_image(mlx, WIDTH, HEIGHT);

        /*
         *
         * mlx_get_data_addr:
         *      -> image pointer
         *      -> bits_per_pixel
         *      -> size_line
         *      -> endian
         * all pram are address, these will be set accordingly to be used
         * returns the image address;
         *
         */
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);


        // formula
        /* (a * a) — (bi * bi) + 2 * (a * bi) */
        
        for (double i = (WIDTH / 2.0) - 300; i <= (WIDTH / 2.0) + 300; i++)
                my_pixel_put(&img, i, HEIGHT / 2, 0xFFFF0000);

        for (double i = (HEIGHT / 2.0) - 300; i <= (HEIGHT / 2.0) + 300; i++)
                my_pixel_put(&img, WIDTH / 2, i, 0xFFFF0000);

 
        /*
         * from -2 -> 2  => -200 -> 200
         */
        for (double x = (WIDTH / 2.0) - 200; x <= (WIDTH / 2.0) + 200; x++) {
                for (double y = (HEIGHT / 2.0) - 200; y <= (HEIGHT / 2.0) + 200; y++) {
                        if (ispoint_diverge(x, y, ITERATION)) {
                                my_pixel_put(&img, x, y, 0xFFFFFFFF);
                        }
                        else
                                my_pixel_put(&img, x, y, 0x00000000);
                }
        }



        /* for (int x = 0; x < HEIGHT; x++) { */
        /*         for (int y = 0; y < WIDTH; y = y + 2) { */
        /*                 my_pixel_put(&img, x, y, 0xFFFFFFFF); */
        /*         } */
        /* } */

        // push image to the window
        mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);

        mlx_loop(mlx);
        (void)mlx_window;
        (void)img;
        return EXIT_SUCCESS;
}
