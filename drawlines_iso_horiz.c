/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines_iso_horiz.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:17:51 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 13:37:49 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawlines_iso_horiz(void *mlx, void *win, t_struct a)
{
	while (a.k < a.rows)
	{
		a.i0 = 0;
		a.pixx = a.iso_x_start - ((PT_D_ORTO * cosf((30 * PI) / 180)) * a.k);
		a.pixy = a.iso_y_start - a.arr[a.i1][a.i0] + (PT_D_ISO_H * a.k);
		while (a.columns > 1)
		{
			a.dy = (a.arr[a.i1][a.i0] - a.arr[a.i1][a.i0 + 1]) + PT_D_ISO_H;
			a.pixels = sqrt((a.dx_default * a.dx_default) + (a.dy * a.dy));
			a.dx = a.dx_default / a.pixels;
			a.dy = a.dy / a.pixels;
			while (a.pixels > 0)
			{
				mlx_pixel_put(mlx, win, a.pixx, a.pixy, colour(a, a.i0, a.i1));
				a.pixx = a.pixx + a.dx;
				a.pixy = a.pixy + a.dy;
				a.pixels--;
			}
			a.i0++;
			a.columns--;
		}
		a.i1++;
		a.k++;
		a.columns = a.columns_temp;
	}
}
