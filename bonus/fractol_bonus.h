/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:35 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/17 15:05:59 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

// macros
# define HEIGHT 900
# define WIDTH 900
# define ITERATION 30
# define BLACK 0x00000000

enum			e_KEYS
{
	ECS = 65307,
	LEFT = 65361,
	RIGHT = 65363,
	UP = 65362,
	DOWN = 65364,
	ZOOMIN = 5,
	ZOOMOUT = 4,
        COLOR = 32, 
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

typedef struct s_fractol
{
	char		*name;
	void		*mlx;
	void		*mlx_window;
	t_complex	z;
	t_img		img;
	double		zoom;
	int			(*fractol)(struct s_fractol *f, double real, double i,
					int iterations);
        int color_shift;
        double x_scale;
        double y_scale;
}				t_fractol;
// ---- utils ----
void			draw_fractol(t_fractol *f);
void			my_pixel_put(t_img *data, int x, int y, int color);
void			ft_print_usage(void);
char			*get_name(char *name);
void			ft_putstr_fd(char *s, int fd);
double			ft_atof(char *string);
double	map(double x, double in_min, double in_max);
int				get_color(int iter);
int				mandelbrot(t_fractol *f, double real, double i, int iterations);
int				julia(t_fractol *f, double real, double i, int iterations);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isdigit(char c);
int				clean(t_fractol *f);

#endif // !FRACTOL_H
