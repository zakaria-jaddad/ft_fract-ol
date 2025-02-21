/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:37:35 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/21 19:27:45 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "./minilibx-linux/mlx_int.h"

typedef struct s_complex
{
	double		real;
	double		i;
}				t_complex;

typedef struct s_fractol
{
	char		*name;
	t_complex	z;
}				t_fractol;

double			ft_atof(const char *string);
int				ft_isdigit(char c);
void			ft_putstr_fd(char *s, int fd);
#endif // !FRACTOL_H
