/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ortographic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:55:39 by tturto            #+#    #+#             */
/*   Updated: 2022/09/05 12:56:47 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	mlx = mlx_init()		=	connects to mlx library
	win = mlx_new_window()	=	creates a window
	mlx_key_hook()			=	connects to function pointer for key events
	mlx_loop()				=	infinite loop to handle events
*/

void	ortographic(t_struct *a)
{
	drawlines_orto_horiz(a->mlx, a->win, *a);
	drawlines_orto_verti(a->mlx, a->win, *a);
	mlx_string_put(a->mlx, a->win, 10, 10, 0xFFFFFF, a->legend);
	mlx_key_hook(a->win, key_events_orto, a);
	mlx_loop(a->mlx);
}
