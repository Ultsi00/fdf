/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:05:38 by tturto            #+#    #+#             */
/*   Updated: 2022/09/01 11:09:57 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	norm_data_to_arr(int *i0, int *i1, int *k)
{
	*i0 = 0;
	*i1 = *i1 + 1;
	*k = *k + 1;
}

static void	data_to_2d_int_arr(char *buf, t_struct *a, int i0, int i1)
{
	char	*temp;
	int		combined;
	int		k;

	combined = 0;
	k = 0;
	while (buf[k] != '\0')
	{
		temp = ft_memalloc(4);
		if ((buf[k] >= '0' && buf[k] <= '9') || buf[k] == '-')
		{
			temp[0] = buf[k++];
			if (buf[k] >= '0' && buf[k] <= '9')
				temp[1] = buf[k++];
			if (buf[k] >= '0' && buf[k] <= '9')
				temp[2] = buf[k++];
			combined = ft_atoi(temp);
			a->arr[i1][i0++] = combined;
		}
		else
			k++;
		ft_memdel((void **)&temp);
		if (buf[k] == '\n')
			norm_data_to_arr(&i0, &i1, &k);
	}
}

static void	data_to_arr(char *buf, t_struct *a)
{
	int	rows;
	int	i1;

	rows = a->rows;
	i1 = 0;
	a->arr = (int **)malloc(sizeof(int *) * a->rows);
	if (!a->arr)
		errors(3);
	while (rows > 0)
	{
		a->arr[i1] = (int *)malloc(sizeof(int) * a->columns);
		if (!a->arr)
			errors(3);
		i1++;
		rows--;
	}
	data_to_2d_int_arr(buf, a, 0, 0);
}

void	read_map_to_arr(t_struct *a, char *buf)
{
	data_to_arr(buf, a);
}
