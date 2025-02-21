/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/21 19:27:50 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
#include "mlx/mlx.h"
#include <stdio.h>


/*
 * TODO: 
 * - creat a window
 * - add an image in the window
 * - add a white image in the window
 * - draw a fractal based on an suit
 * - parse input
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


int colors_number = 16;
int colors[] = {
    0xFF19071A,  // 25, 7, 26
    0xFF09012F,  // 9, 1, 47
    0xFF040449,  // 4, 4, 73
    0xFF000764,  // 0, 7, 100
    0xFF0C2C8A,  // 12, 44, 138
    0xFF1852B1,  // 24, 82, 177
    0xFF397DD1,  // 57, 125, 209
    0xFF421E0F,  // 66, 30, 15 --
    0xFF86B5E5,  // 134, 181, 229
    0xFFD3ECF8,  // 211, 236, 248
    0xFFF1E9BF,  // 241, 233, 191
    0xFFF8C95F,  // 248, 201, 95
    0xFFFFAA00,  // 255, 170, 0
    0xFFCC8000,  // 204, 128, 0
    0xFF995700,  // 153, 87, 0
    0xFF6A3403   // 106, 52, 3
};

// macros
#define HEIGHT 600
#define WIDTH  800
#define ITERATION 42

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

        // calculate the position of the (x, y) pixle and return it
        // since char is 1 byte that's why it's used
        // color is just and integer 0xFFFFFF00 representation if Alpha, red, green and blue
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int ft_abs(int x)
{
        if (x < 0)
                return x * -1;
        return x;
}

int ft_strcmp(const char *s1, const char *s2) {
   while (*s1 != '\0' && *s2 != '\0'  && *s1 == *s2) {
      s1++;
      s2++;
   }
   return *s1 - *s2;
}
/* Mandelbrot_set */
// (a * a) + (a * bi) + (a* bi) + (bi * bi) → (a * a) — (b * b) + 2 * (a * bi).


/* check weather a point diverge or not */
int ispoint_diverge(t_complex z, double real, double i, int iterations)
{

    for (int iteration = 0; iteration < iterations; iteration++) {
        double tmp_real = (z.real * z.real) - (z.i * z.i) + real   ;
        z.i = 2 * (z.real * z.i) + i;
        z.real = tmp_real;

        // Correct divergence check: If |z| > 2, return 0
        if ((z.real * z.real + z.i * z.i) > 4)
            return (colors[((iteration  * ft_abs((int)(z.i + z.real)))  % colors_number)]);
    }
    return 0;
}


double map(double x, double in_min, double in_max, double out_min, double out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

char *get_name(char *name)
{
        if (ft_strcmp(name, "mandelbrot") == 0)
                return "mandelbrot";
        else if (ft_strcmp(name, "julia") == 0)
                return "julia";
        return NULL;
}


int ft_isvalid_julia(char *real, char *i, double *z_real, double *z_i)
{
        if (real == NULL || i == NULL)
                return 0;
        *z_real = ft_atof(real);
        *z_i = ft_atof(i);
        return 1;
}

/*
 * ./fractol mandelbrot 
 * ./fractol julia <real> <i>
 */
int main(int argc, char **argv)
{
        void *mlx;
        void *mlx_window;
        t_img img;
        t_fractol f;

        
        // parsing
        if (argc < 2)
                return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n", 2), EXIT_FAILURE);
        f.name = get_name(argv[1]);
        if (f.name == NULL)
                return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n", 2), EXIT_FAILURE);
        if (ft_strcmp("julia", f.name) == 0 && ft_isvalid_julia(argv[2], argv[3], &f.z.real, &f.z.i) == 0)
                return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n", 2), EXIT_FAILURE);
        if (ft_strcmp("mandelbrot", f.name) == 0)
                f.z.real = (f.z.i = 0, 0);



        mlx = mlx_init();


        mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Fract-ol");


        img.img = mlx_new_image(mlx, WIDTH, HEIGHT);


        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);



        for (long x = 0; x < WIDTH; x++) {
                for (long y = 0; y < HEIGHT; y++) {
                        double real = map(x, 0, WIDTH, -2, 2);
                        double i = map(y, 0, HEIGHT, -2, 2);
                        int color = ispoint_diverge(f.z, real, i, ITERATION);
                        if (color != 0)
                                my_pixel_put(&img, x, y, color);
                }
        }
        mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);

        mlx_loop(mlx);
        (void)mlx_window;
        (void)img;
        return EXIT_SUCCESS;
}
