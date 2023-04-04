/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:14:09 by tturto            #+#    #+#             */
/*   Updated: 2022/08/31 12:01:45 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int nb)
{
	if (nb == 1)
		ft_putstr("Map reading error. Map must not contain letters.\n");
	if (nb == 2)
		ft_putstr("Map must contain atleast one element.\n");
	if (nb == 3)
		ft_putstr("Error in memory allocation.\n");
	if (nb == 4)
		ft_putstr("Send only one map file, which has an .fdf extension.\n");
	if (nb == 5)
		ft_putstr("Map reading error. Ensure the map file exists.\n");
	if (nb == 6)
		ft_putstr("Source map is to follow a standard.\n");
	exit(0);
}
