/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:06:15 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/14 00:37:58 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

char	*get_name(char *name)
{
	if (ft_strcmp(name, "mandelbrot") == 0)
		return ("mandelbrot");
	else if (ft_strcmp(name, "julia") == 0)
		return ("julia");
	return (NULL);
}
