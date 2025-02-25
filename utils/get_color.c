/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:33 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/23 00:10:08 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color_escaping_norm(int n)
{
	if (n == 6)
		return (0xFF397DD1);
	else if (n == 7)
		return (0xFF421E0F);
	else if (n == 8)
		return (0xFF86B5E5);
	else if (n == 9)
		return (0xFFD3ECF8);
	else if (n == 10)
		return (0xFFF1E9BF);
	else if (n == 11)
		return (0xFFF8C95F);
	else if (n == 12)
		return (0xFFFFAA00);
	else if (n == 13)
		return (0xFFCC8000);
	else if (n == 14)
		return (0xFF995700);
	else
		return (0xFF6A3403);
}

int	get_color(double mu)
{
	int	n;

	n = (int)mu % 16;
	if (n == 0)
		return (0xFF19071A);
	else if (n == 1)
		return (0xFF09012F);
	else if (n == 2)
		return (0xFF040449);
	else if (n == 3)
		return (0xFF000764);
	else if (n == 4)
		return (0xFF0C2C8A);
	else if (n == 5)
		return (0xFF1852B1);
	else
		return (get_color_escaping_norm(n));
}
