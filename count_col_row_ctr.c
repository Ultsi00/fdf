/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_col_row_ctr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:41:01 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 13:32:19 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	start_point(t_struct *a)
{
	a->orto_x_start = WIDTH / 2 - (a->columns / 2 * PT_D_ORTO);
	a->orto_y_start = HEIGHT / 2 - (a->rows / 2 * PT_D_ORTO);
	if (a->rows < a->columns)
	{
		a->iso_x_start = (WIDTH * 0.40);
		a->iso_y_start = HEIGHT * 0.40 - (a->rows / 2 * PT_D_ORTO);
	}
	else
	{
		a->iso_x_start = WIDTH / 2;
		a->iso_y_start = HEIGHT / 2 - (a->rows / 2 * PT_D_ORTO);
	}
}

/*
	rows_temp & columns_temp are used in isometric projection draw loop
*/

void	count_col_row_ctr(char *buf, t_struct *a)
{
	int	rows_count;
	int	columns_count;
	int	k;

	rows_count = 0;
	columns_count = 0;
	k = 0;
	while (a->ret > 0)
	{
		if (buf[k] >= '0' && buf[k] <= '9'
			&& (buf[k + 1] == ' ' || buf[k + 1] == '\n' || buf[k + 1] == '\0'))
			columns_count++;
		if (buf[k] == '\n' || buf[k] == '\0')
			rows_count++;
		if ((buf[k] == '\n' && buf[k + 1] == '\n'))
			break ;
		a->ret--;
		k++;
	}
	columns_count = columns_count / rows_count;
	a->rows = rows_count;
	a->columns = columns_count;
	a->rows_temp = a->rows;
	a->columns_temp = a->columns;
	start_point(a);
}
