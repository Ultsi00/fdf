/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines_orto_horiz.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:35:31 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 11:38:38 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	"pixels" is the number of steps between coordinate points.
	"pixel*" is the starting coordinate for drawing
	mlx_key_hook()	=	connects to function pointer for key events
	mlx_loop()		=	infinite loop to handle events
*/

static void	norm_orto_h(unsigned short int *i0, int *cols, int *p, t_struct *a)
{
	*i0 = 0;
	*cols = a->columns;
	*p = a->orto_x_start;
}

void	drawlines_orto_horiz(void *mlx, void *win, t_struct a)
{
	t_orto	h;

	a.i1 = 0;
	h.pixy = a.orto_y_start;
	while (a.rows > 0)
	{
		norm_orto_h(&a.i0, &h.columns, &h.pixx, &a);
		while (h.columns > 1)
		{
			h.pixels = PT_D_ORTO;
			while (h.pixels > 0)
			{
				mlx_pixel_put(mlx, win, h.pixx, h.pixy, colour(a, a.i0, a.i1));
				h.pixx = h.pixx + 1;
				h.pixels--;
			}
			a.i0++;
			h.columns--;
		}
		a.i1++;
		h.pixy = h.pixy + PT_D_ORTO;
		a.rows--;
	}
	h.pixy = h.pixy - PT_D_ORTO;
	mlx_pixel_put(mlx, win, h.pixx, h.pixy, 0x44D62C);
}
