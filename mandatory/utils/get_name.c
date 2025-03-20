/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:06:15 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 13:20:30 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

char	*get_name(char *name)
{
	name = ft_strtrim(name, " ");
	if (name == NULL)
		return (NULL);
	if (ft_strcmp(name, "mandelbrot") == 0)
		return (free(name), name = NULL, "mandelbrot");
	else if (ft_strcmp(name, "julia") == 0)
		return (free(name), name = NULL, "julia");
	(void)!(free(name), name = NULL);
	return (NULL);
}
