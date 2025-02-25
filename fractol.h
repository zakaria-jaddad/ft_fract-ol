/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:35 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/25 11:57:27 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

// macros
# define HEIGHT 600
# define WIDTH 700
# define ITERATION 30
# define BLACK 0x00000000

enum			KEYS
{
	ECS = 65307,
	LEFT = 65361,
	RIGHT = 65363,
	UP = 65362,
	DOWN = 65364,
	COLOR = 32,
	ZOOMIN = 5,
	ZOOMOUT = 4,
};

// struct to hold information about image
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_zoom
{
	double		target_zoom;
	double		current_zoom;
	double		zoom_speed;
	double		target_x;
	double		target_y;
	double		current_x;
	double		current_y;
}				t_zoom;

typedef struct s_view
{
	double		center_x;
	double		center_y;
	double		zoom;
}				t_view;

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*mlx_window;
	t_complex	z;
	t_img		img;
	t_zoom		zoom;
        t_view          view;
	int			(*fractol)(struct s_fractol *f, double real, double i,
					int iterations);
	int			color_index;

}				t_fractol;

// ---- utils ----
void			draw_fractol(t_fractol *f);
void			my_pixel_put(t_img *data, int x, int y, int color);
char			*get_name(char *name);
void			ft_putstr_fd(char *s, int fd);
double			ft_atof(char *string);
double			map(double x, double in_min, double in_max, double out_min,
					double out_max);
int				get_color(double mu);
int				mandelbrot(t_fractol *f, double real, double i, int iterations);
int				julia(t_fractol *f, double real, double i, int iterations);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(char c);
int				ft_abs(int x);

#endif // !FRACTOL_H
