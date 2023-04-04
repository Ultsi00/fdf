/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:25:31 by tturto            #+#    #+#             */
/*   Updated: 2022/08/24 21:35:38 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_min_max(t_struct *a)
{
	int	i0;
	int	i1;

	i0 = 0;
	i1 = 0;
	a->min = a->arr[i1][i0];
	a->max = a->arr[i1][i0];
	while (i1 < a->rows)
	{
		while (i0 < a->columns)
		{
			if (a->min > a->arr[i1][i0])
				a->min = a->arr[i1][i0];
			if (a->max < a->arr[i1][i0])
				a->max = a->arr[i1][i0];
			i0++;
		}
		i0 = 0;
		i1++;
	}
}
