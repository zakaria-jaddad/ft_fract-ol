/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:58:27 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/19 23:49:59 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	ft_print_usage(void)
{
	ft_putstr_fd("Usage:\n ", 2);
	ft_putstr_fd("./fractol mandelbrot\n ", 2);
	ft_putstr_fd("./fractol julia <real> <i>\n ", 2);
	ft_putstr_fd("./fractol burning_ship\n", 2);
}
