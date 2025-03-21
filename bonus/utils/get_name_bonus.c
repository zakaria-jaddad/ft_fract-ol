/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:06:15 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/21 11:44:29 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

char	*get_name(char *name)
{
	name = ft_strtrim(name, " ");
	if (name == NULL)
		return (NULL);
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (free(name), name = NULL, "mandelbrot");
	else if (ft_strcmp(name, "julia") == 0)
		return (free(name), name = NULL, "julia");
	else if (ft_strcmp(name, "burning_ship") == 0)
		return (free(name), name = NULL, "burning_ship");
	(void)!(free(name), name = NULL);
	return (NULL);
}
