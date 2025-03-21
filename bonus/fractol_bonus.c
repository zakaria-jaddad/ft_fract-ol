/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:11:37 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/21 15:40:07 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol_bonus.h"

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == ZOOMIN)
		f->zoom.target_zoom *= 1.1;
	else if (keycode == ZOOMOUT && f->view.zoom > 1)
		f->zoom.target_zoom /= 1.1;
	zoom(x, y, f);
	draw_fractol(f);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == ECS)
		return (clean(f));
	if (keycode == COLOR)
		f->color_shift += 20;
	else if (keycode == RIGHT)
		f->view.center_x += 0.1;
	else if (keycode == LEFT)
		f->view.center_x -= 0.1;
	else if (keycode == DOWN)
		f->view.center_y -= 0.1;
	else if (keycode == UP)
		f->view.center_y += 0.1;
	draw_fractol(f);
	return (0);
}

void	ft_fractol_parsing(int argc, char **argv, t_fractol *f)
{
	f->z.i = (f->z.real = 0, f->color_shift = 0, 0);
	(void)!(f->x_scale = 0, f->y_scale = 0);
	f->view = (t_view){0, 0, 1.0};
	f->zoom = (t_zoom){1.0, 1.0, 0.1, 0, 0, 0};
	if (argc < 2)
		(void)(ft_print_usage(), exit(EXIT_FAILURE));
	f->name = get_name(argv[1]);
	if (f->name == NULL)
		(void)(ft_print_usage(), exit(EXIT_FAILURE));
	if (ft_strcmp("julia", f->name) == 0)
	{
		if (!argv[2] || !argv[3] || argv[4])
			(void)(ft_print_usage(), exit(EXIT_FAILURE));
		(void)!(f->z.real = ft_atof(argv[2]), f->z.i = ft_atof(argv[3]));
		f->fractol = julia;
	}
	if (ft_strcmp("mandelbrot", f->name) == 0 || ft_strcmp("burning_ship",
			f->name) == 0)
	{
		if (argc > 2)
			(void)(ft_print_usage(), exit(EXIT_FAILURE));
		if (ft_strcmp("mandelbrot", f->name) == 0)
			return (f->fractol = mandelbrot, (void)0);
		f->fractol = burning_ship;
	}
}

void	ft_init_fractal(t_fractol *f)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit(EXIT_FAILURE);
	f->mlx_window = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (f->mlx_window == NULL)
	{
		mlx_destroy_display(f->mlx);
		f->mlx = (free(f->mlx), NULL);
		exit(EXIT_FAILURE);
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img.img == NULL)
	{
		mlx_destroy_window(f->mlx, f->mlx_window);
		mlx_destroy_display(f->mlx);
		f->mlx = (free(f->mlx), NULL);
		exit(EXIT_FAILURE);
	}
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_length, &f->img.endian);
	if (f->img.addr == NULL)
		clean(f);
}

/*
 * ./fractol_bonus mandelbrot
 * ./fractol_bonus julia <real> <i>
 * ./fractol_bonus burning_ship
 */
int	main(int argc, char **argv)
{
	t_fractol	f;

	ft_fractol_parsing(argc, argv, &f);
	ft_init_fractal(&f);
	draw_fractol(&f);
	mlx_mouse_hook(f.mlx_window, mouse_hook, &f);
	mlx_key_hook(f.mlx_window, key_hook, &f);
	mlx_hook(f.mlx_window, 17, 0, clean, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}
