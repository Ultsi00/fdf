/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:24:21 by tturto            #+#    #+#             */
/*   Updated: 2022/09/05 12:58:42 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	argv_input(char *argv)
{
	size_t	length;
	size_t	n;
	int		i;
	char	extension[5];

	length = ft_strlen((const char *)argv);
	n = length - 4;
	i = 0;
	while (n < length)
		extension[i++] = argv[n++];
	extension[4] = '\0';
	if (extension[0] != '.')
		errors(4);
	if (extension[1] != 'f' || extension[2] != 'd' || extension[3] != 'f')
		errors(4);
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	a;
	char		buf[BUFF_SIZE + 1];

	if (argc != 2 || argv_input(argv[1]) != 1)
		errors(4);
	read_and_validate(buf, argv, &a);
	count_col_row_ctr(buf, &a);
	read_map_to_arr(&a, buf);
	count_min_max(&a);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, WIDTH, HEIGHT, "FDF");
	a.legend = "ESC = quit | 1 = Ortographic | 2 = Isometric";
	ortographic(&a);
}
