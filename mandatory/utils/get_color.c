/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:33 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/14 00:56:28 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(double mu)
{
	int	colors[16];

	colors[0] = 0xFF19071A;
	colors[1] = 0xFF09012F;
	colors[2] = 0xFF040449;
	colors[3] = 0xFF000764;
	colors[4] = 0xFF0C2C8A;
	colors[5] = 0xFF1852B1;
	colors[6] = 0xFF397DD1;
	colors[7] = 0xFF421E0F;
	colors[8] = 0xFF86B5E5;
	colors[9] = 0xFFD3ECF8;
	colors[10] = 0xFFF1E9BF;
	colors[11] = 0xFFF8C95F;
	colors[12] = 0xFFFFAA00;
	colors[13] = 0xFFCC8000;
	colors[14] = 0xFF995700;
	colors[15] = 0xFF6A3403;
	return (colors[(int)mu % 16]);
}
