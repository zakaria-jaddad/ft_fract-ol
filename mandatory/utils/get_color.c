/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:33 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/14 10:29:03 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_color(int iter)
{
	int	colors[16];

	colors[0] = 0xFF0B004B;
	colors[1] = 0xFF160073;
	colors[2] = 0xFF21009B;
	colors[3] = 0xFF2C00C3;
	colors[4] = 0xFF3700EB;
	colors[5] = 0xFF4823F2;
	colors[6] = 0xFF5946F9;
	colors[7] = 0xFF6B69FF;
	colors[8] = 0xFF7D8CFF;
	colors[9] = 0xFF9FB1FF;
	colors[10] = 0xFFC1D6FF;
	colors[11] = 0xFFE3FBFF;
	colors[12] = 0xFFFDEBCC;
	colors[13] = 0xFFF7C590;
	colors[14] = 0xFFD28A40;
	colors[15] = 0xFFAA3F00;
	return (colors[iter % 16]);
}
