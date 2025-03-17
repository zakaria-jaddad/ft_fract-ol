/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:44:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/13 23:36:03 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static void	atof_body(double *val, double *power, int *i, char *string)
{
	while (ft_isdigit(string[*i]))
	{
		*val = *val * 10 + (string[*i] - '0');
		*i = *i + 1;
	}
	if (string[*i] == '.')
		*i = *(i) + 1;
	while (ft_isdigit(string[*i]))
	{
		*val = *val * 10 + (string[*i] - '0');
		*i = *i + 1;
		*power = *power * 10.0;
	}
}

double	ft_atof(char *string)
{
	int		i;
	int		sign;
	double	val;
	double	power;

	(void)!(sign = 1, val = 0.0, power = 1.0, i = 0, 0);
	while (string[i] == ' ')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	atof_body(&val, &power, &i, string);
	while (string[i] == ' ')
		i++;
	if (string[i] != 0)
	{
		ft_putstr_fd(string, 2);
		ft_putstr_fd("\nInvalid Number\n", 2);
		exit(EXIT_FAILURE);
	}
	return (sign * val / power);
}
