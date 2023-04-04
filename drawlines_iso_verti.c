/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines_iso_verti.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 20:44:46 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 13:37:54 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawlines_iso_verti(void *mlx, void *win, t_struct a)
{
	while (a.k < a.columns)
	{
		a.i1 = 0;
		a.pixx = a.iso_x_start + ((PT_D_ORTO * cosf((30 * PI) / 180)) * a.k);
		a.pixy = a.iso_y_start - a.arr[a.i1][a.i0] + (PT_D_ISO_H * a.k);
		while (a.rows > 1)
		{
			a.dy = (a.arr[a.i1][a.i0] - a.arr[a.i1 + 1][a.i0]) + PT_D_ISO_H;
			a.pixels = sqrt((a.dx_default * a.dx_default) + (a.dy * a.dy));
			a.dx = a.dx_default / a.pixels;
			a.dy = a.dy / a.pixels;
			while (a.pixels > 0)
			{
				mlx_pixel_put(mlx, win, a.pixx, a.pixy, colour(a, a.i0, a.i1));
				a.pixx = a.pixx - a.dx;
				a.pixy = a.pixy + a.dy;
				a.pixels--;
			}
			a.i1++;
			a.rows--;
		}
		a.i0++;
		a.k++;
		a.rows = a.rows_temp;
	}
}
