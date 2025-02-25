/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:59:16 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/22 15:00:16 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double x, double in_min, double in_max, double out_min,
		double out_max)
{
	return ((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
