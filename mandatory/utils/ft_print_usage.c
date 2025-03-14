/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:58:27 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/13 23:58:46 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_print_usage(void)
{
	ft_putstr_fd("Usage:\n ", 2);
	ft_putstr_fd("./fractol mandelbrot\n ", 2);
	ft_putstr_fd("./fractol julia <real> <i>\n", 2);
}
