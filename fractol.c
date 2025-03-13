/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/09 00:44:07 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TODO:
 * - creat a window
 * - add an image in the window
 * - add a white image in the window
 * - draw a fractal based on an suit
 * - parse input
 * - add esc key hook
 * - space change color
 */


int clean(t_fractol *f)
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
}

int mouse_hook(int keycode, int x, int y, t_fractol *f) {

        /* (void)x; */
        if (keycode == ZOOMIN)  {
                double	mouse_x;
                double	mouse_y;

                mouse_x = f->zoom.center_x
                        - (x - 320) * 0.00625 / f->zoom.zoom;
                mouse_y = f->zoom.center_y
                        + (y - 240) * 0.00625 / f->zoom.zoom;
                f->zoom.target_zoom /= 1.1;
                f->zoom.target_x = mouse_x
                        + (x - 320) * 0.00625 / f->zoom.target_zoom;
                f->zoom.target_y = mouse_y
                        - (y - 240) * 0.00625 / f->zoom.target_zoom;
        }
        else if (keycode == ZOOMOUT && f->zoom.zoom > ZOOMOUT_MAX) {
                double	mouse_x;
                double	mouse_y;

                mouse_x = f->zoom.center_x
                        + (x - 320) * 0.00625 / f->zoom.zoom;
                mouse_y = f->zoom.center_y
                        - (y - 240) * 0.00625 / f->zoom.zoom;
                f->zoom.target_zoom *= 1.1;
                f->zoom.target_x = mouse_x
                        - (x - 320) * 0.00625 / f->zoom.target_zoom;
                f->zoom.target_y = mouse_y
                        + (y - 240) * 0.00625 / f->zoom.target_zoom;
        }
        /* x = y + 1; */
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
        if (keycode == ECS)
                clean(f);
        if (keycode == COLOR) {
                f->color_index += 20;
                draw_fractol(f);
        }
	return (0);
}
int animation(t_fractol *f) {
	f->zoom.current_zoom
		+= (f->zoom.target_zoom - f->zoom.current_zoom) * 1;
	f->zoom.current_x
		+= (f->zoom.target_x - f->zoom.current_x) * 1;
	f->zoom.current_y
		+= (f->zoom.target_y - f->zoom.current_y) * 1;
	f->zoom.zoom = f->zoom.current_zoom;
	f->zoom.center_x = f->zoom.current_x;
	f->zoom.center_y = f->zoom.current_y;
        draw_fractol(f);
        return 0;
}

/*
 * ./fractol mandelbrot
 * ./fractol julia <real> <i>
 */
int	main(int argc, char **argv)
{

	t_fractol	f;
	f.zoom = (t_zoom){1.0, 1.0, 0.1, 0, 0, 0, 0, 0, 0, 0};
        f.offset_x = 0;
        f.offset_y = 0;
        f.color_index = 0;
        f.z.i = 0;
        f.z.real = 0;

	// parsing
	if (argc < 2)
		return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n",
				2), EXIT_FAILURE);
	f.name = get_name(argv[1]);
	if (f.name == NULL)
		return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n",
				2), EXIT_FAILURE);
	if (ft_strcmp("julia", f.name) == 0) {
                if (!argv[2] || !argv[3])
                        return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n",
                                             2), EXIT_FAILURE);
                f.z.real = ft_atof(argv[2]);
                f.z.i = ft_atof(argv[3]);
                f.fractol = julia;
        }
	if (ft_strcmp("mandelbrot", f.name) == 0 ) {
                if (argc > 2)
		        return (ft_putstr_fd("Usage:\n ./fractol mandelbrot\n ./fractol julia <real> <i>\n",
		        		2), EXIT_FAILURE);
                f.fractol = mandelbrot;
        }



	f.mlx = mlx_init();
	f.mlx_window = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract-ol");
	/* f.img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT); */
        f.img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);

	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel, &f.img.line_length,
			&f.img.endian);

        draw_fractol(&f);
	// add keyhook to window
        mlx_mouse_hook(f.mlx_window, mouse_hook, &f);
	mlx_key_hook(f.mlx_window, key_hook, &f);
        mlx_hook(f.mlx_window, 17, 0, clean, &f);
        mlx_loop_hook(f.mlx, animation, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}

