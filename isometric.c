/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 20:26:33 by tturto            #+#    #+#             */
/*   Updated: 2022/09/05 12:56:56 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	angle between any two of the axes is 120 degrees.
	deltaX doesnt vary in isometric proj., thus dx_default, deltaY may vary.
*/

void	isometric(t_struct *a)
{
	a->k = 0;
	a->i0 = 0;
	a->i1 = 0;
	a->dx_default = PT_D_ORTO * cosf((30 * PI) / 180);
	drawlines_iso_horiz(a->mlx, a->win, *a);
	drawlines_iso_verti(a->mlx, a->win, *a);
	mlx_string_put(a->mlx, a->win, 10, 10, 0xFFFFFF, a->legend);
	mlx_key_hook(a->win, key_events_orto, a);
	mlx_loop(a->mlx);
}
