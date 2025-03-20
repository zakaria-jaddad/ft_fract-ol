/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:44:18 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 17:02:02 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

static void	ft_atof_error(char *string)
{
	ft_putstr_fd(string, 2);
	ft_putstr_fd("\nInvalid Number\n", 2);
        (free(string), string = NULL);
	exit(EXIT_FAILURE);
}

static int	atof_body(double *val, double *power, int *i, char *string)
{
	while (ft_isdigit(string[*i]))
	{
		*val = *val * 10 + (string[*i] - '0');
		*i = *i + 1;
	}
	if (string[*i] == '.')
	{
		*i = *(i) + 1;
		if (string[*i] == 0 && ft_strlen(string) == 1)
			return (0);
	}
	while (ft_isdigit(string[*i]))
	{
		*val = *val * 10 + (string[*i] - '0');
		*i = *i + 1;
		*power = *power * 10.0;
	}
	return (1);
}

double	ft_atof(char *string)
{
	int		i;
	int		sign;
	double	val;
	double	power;

	(void)!(sign = 1, val = 0.0, power = 1.0, i = 0, 0);
	string = ft_strtrim(string, " ");
	if (string == NULL)
		(void)(free(string), string = NULL,
			ft_putstr_fd("ft_strtrim Allocation Error\n", 2),
			exit(EXIT_FAILURE));
        if (string[i] == 0)
                ft_atof_error(string);
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i++] == '-')
			sign = -1;
                if ((string[i] == '.' && string[i + 1] == 0) || string[i] == 0)
                        ft_atof_error(string);
	}
	if (atof_body(&val, &power, &i, string) == 0 || string[i] != 0)
                ft_atof_error(string);
	(void)!(free(string), string = NULL);
	return (sign * val / power);
}
