/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:31:29 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 17:06:52 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../fractol_bonus.h"

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}
