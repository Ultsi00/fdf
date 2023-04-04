/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:46:31 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 12:01:29 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	validate_map(char *buf, int ret)
{
	int	i;

	i = 0;
	if (buf[0] == '\n')
		errors(6);
	while (ret > 0)
	{
		if (buf[i] != '\n' && buf[i] != ' ' && (buf[i] < 48 || buf[i] > 57)
			&& buf[i] != '-')
			errors(1);
		i++;
		ret--;
	}
}

void	read_and_validate(char *buf, char **argv, t_struct *a)
{
	int	fd;
	int	ret;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		errors(5);
	ret = read(fd, buf, BUFF_SIZE);
	a->ret = ret;
	if (ret < 1)
		errors(2);
	buf[ret] = '\0';
	validate_map(buf, ret);
	close(fd);
}
