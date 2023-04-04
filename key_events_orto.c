/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_orto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:40:18 by tturto            #+#    #+#             */
/*   Updated: 2022/09/01 11:09:15 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
	MAC keyboard codes:
	53	=	"ESC"
	18	=	"1"
	19	=	"2"
*/

int	key_events_esc(int key, t_struct *a)
{
	int	i;

	i = 0;
	if (key == 53)
	{
		mlx_destroy_window(a->mlx, a->win);
		while (i < a->rows)
		{
			free(a->arr[i]);
			i++;
		}
		exit(0);
	}
	return (0);
}

int	key_events_iso(int key, t_struct *a)
{
	if (key == 19)
	{
		mlx_clear_window(a->mlx, a->win);
		isometric(a);
	}
	key_events_esc(key, a);
	return (0);
}

int	key_events_orto(int key, t_struct *a)
{
	if (key == 18)
	{
		mlx_clear_window(a->mlx, a->win);
		ortographic(a);
	}
	key_events_iso(key, a);
	key_events_esc(key, a);
	return (0);
}
