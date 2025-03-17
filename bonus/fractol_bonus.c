/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:47:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/17 15:07:17 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol_bonus.h"

int	mouse_hook(int keycode, int x, int y, t_fractol *f)
{
        double z;

        z = 0;
        (void)x;
        (void)y;
	if (keycode == ZOOMIN)
	{
                z = .9;
		f->zoom *= 1.1;
	}
	else if (keycode == ZOOMOUT && f->zoom > 1)
	{
                z = 1.1;
		f->zoom /= 1.1;
	}
	draw_fractol(f);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
        if (keycode == COLOR)
        {
                f->color_shift += 20;
                draw_fractol(f);
        }
        else if (keycode == RIGHT)
        {
               f->x_scale -= map(f->x_scale - 5, 0, WIDTH) / f->zoom ;
               draw_fractol(f);
        }
        else if (keycode == LEFT)
        {
               f->x_scale += map(f->x_scale - 5, 0, WIDTH) / f->zoom ;
               draw_fractol(f);
        }
        else if(keycode == DOWN)
        {
               f->y_scale += map(f->y_scale - 5, 0, HEIGHT) / f->zoom ;
               draw_fractol(f);
        }
        else if(keycode == UP)
        {
               f->y_scale -= map(f->y_scale - 5, 0, HEIGHT) / f->zoom ;
               draw_fractol(f);
        }
        else if (keycode == ECS)
                clean(f);
	return (0);
}

void	ft_fractol_parsing(int argc, char **argv, t_fractol *f)
{
	f->z.i = (f->z.real = 0, f->zoom = 1, f->color_shift = 0, 0);
        f->x_scale = 0;
        f->y_scale = 0;
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
		f->fractol = julia;
	}
	if (ft_strcmp("mandelbrot", f->name) == 0)
	{
		if (argc > 2)
			(void)(ft_print_usage(), exit(EXIT_FAILURE));
		f->fractol = mandelbrot;
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
	if (f->img.addr == NULL) {
		clean(f);
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
	ft_init_fractal(&f);
	draw_fractol(&f);
	mlx_mouse_hook(f.mlx_window, mouse_hook, &f);
	mlx_key_hook(f.mlx_window, key_hook, &f);
	mlx_hook(f.mlx_window, 17, 0, clean, &f);
	mlx_loop(f.mlx);
	return (EXIT_SUCCESS);
}
