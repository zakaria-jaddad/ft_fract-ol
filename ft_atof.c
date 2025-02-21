/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:44:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/02/21 19:28:13 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *string)
{
	int i, sign;
	double val, power;
	// skip white spaces
	for (i = 0; string[i] == ' '; i++)
		;
	// check for the sign
	sign = (string[i] == '-') ? -1 : 1;
	if (string[i] == '+' || string[i] == '-')
		i++;
	// start iterating
	for (val = 0.0; ft_isdigit(string[i]); i++)
		val = val * 10 + (string[i] - '0');
	if (string[i] == '.')
		i++;
	for (power = 1.0; ft_isdigit(string[i]); i++)
	{
		val = val * 10 + (string[i] - '0');
		power *= 10;
	}

        // check end of string
        if (string[i] != 0) {
                ft_putstr_fd((char *) string, 2);
                ft_putstr_fd(" Invalid Number\n", 2);
                exit(EXIT_FAILURE);
        }
	return (sign * val / power);
}
