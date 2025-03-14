/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/14 00:57:07 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"
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

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	(void)x;
	if (keycode == 5)
	{
		f->zoom += .5;
	}
	else if (keycode == ZOOMOUT && f->zoom > 1)
	{
		f->zoom -= .5;
	}
	x = y + 1;
	draw_fractol(f);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ECS)
		clean(f);
	return (0);
}

void	ft_fractol_parsing(int argc, char **argv, t_fractol *f)
{
	f->z.i = (f->z.real = 0, f->zoom = 1, 0);
	if (argc < 2)
		(void)(ft_print_usage(), exit(EXIT_FAILURE));
	f->name = get_name(argv[1]);
	if (f->name == NULL)
		(void)(ft_print_usage(), exit(EXIT_FAILURE));
	if (ft_strcmp("julia", f->name) == 0)
	{
		if (!argv[2] || !argv[3] || argv[4])
			(void)(ft_print_usage(), exit(EXIT_FAILURE));
		f->z.real = ft_atof(argv[2]);
		f->z.i = ft_atof(argv[3]);
		printf("%f, %f", f->z.real, f->z.i);
		f->fractol = julia;
	}
	if (ft_strcmp("mandelbrot", f->name) == 0)
	{
		if (argc > 2)
			(void)(ft_print_usage(), exit(EXIT_FAILURE));
		f->fractol = mandelbrot;
	}
}

/*
 * ./fractol mandelbrot
 * ./fractol julia <real> <i>
 */
int	main(int argc, char **argv)
{
	t_fractol	f;

	ft_fractol_parsing(argc, argv, &f);
	f.mlx = mlx_init();
	f.mlx_window = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract-ol");
	f.img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.img.addr = mlx_get_data_addr(f.img.img, &f.img.bits_per_pixel,
			&f.img.line_length, &f.img.endian);
	draw_fractol(&f);
	mlx_mouse_hook(f.mlx_window, mouse_hook, &f);
	mlx_key_hook(f.mlx_window, key_hook, &f);
	mlx_hook(f.mlx_window, 17, 0, clean, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}
