/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines_orto_verti.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 17:23:43 by tturto            #+#    #+#             */
/*   Updated: 2022/08/24 22:25:53 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	"pixels" is the number of steps between coordinate points.
	"pixel*" is the starting coordinate for drawing
	mlx_key_hook()	=	connects to function pointer for key events
	mlx_loop()		=	infinite loop to handle events
*/

static void	norm_orto_v(unsigned short int *i1, int *rows, int *d, t_struct *a)
{
	*i1 = 0;
	*rows = a->rows;
	*d = 0;
}

void	drawlines_orto_verti(void *mlx, void *win, t_struct a)
{
	t_orto	v;

	a.i0 = 0;
	v.pixx = a.orto_x_start;
	while (a.columns > 0)
	{
		norm_orto_v(&a.i1, &v.rows, &v.d, &a);
		while (v.rows > 1)
		{
			v.pixels = PT_D_ORTO;
			v.pixy = a.orto_y_start + v.d;
			while (v.pixels > 0)
			{
				mlx_pixel_put(mlx, win, v.pixx, v.pixy, colour(a, a.i0, a.i1));
				v.pixy = v.pixy + 1;
				v.pixels--;
			}
			a.i1++;
			v.d = v.d + PT_D_ORTO;
			v.rows--;
		}
		a.i0++;
		v.pixx = v.pixx + PT_D_ORTO;
		a.columns--;
	}
}
