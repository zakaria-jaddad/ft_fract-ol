/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zajaddad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:53:28 by zajaddad          #+#    #+#             */
/*   Updated: 2025/03/20 17:16:26 by zajaddad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	zoom(int x, int y, t_fractol *f)
{
	double	mx;
	double	my;
	double	mouse_x;
	double	mouse_y;

	mx = map(x, 0, WIDTH);
	my = map(y, 0, HEIGHT);
	mouse_x = f->view.center_x + mx / f->view.zoom;
	mouse_y = f->view.center_y - my / f->view.zoom;
	f->zoom.target_x = mouse_x - mx / f->zoom.target_zoom;
	f->zoom.target_y = mouse_y + my / f->zoom.target_zoom;
	f->zoom.current_zoom += (f->zoom.target_zoom - f->zoom.current_zoom) * 1;
	f->zoom.current_x += (f->zoom.target_x - f->zoom.current_x) * 1;
	f->zoom.current_y += (f->zoom.target_y - f->zoom.current_y) * 1;
	f->view.zoom = f->zoom.current_zoom;
	f->view.center_x = f->zoom.current_x;
	f->view.center_y = f->zoom.current_y;
}

