/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:24:45 by tturto            #+#    #+#             */
/*   Updated: 2022/09/05 12:56:25 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	fcntl	=	open()
	stdlib	=	malloc()
	unistd	=	close()
	int		mlx_key_hook(void *win, int (*funct_ptr)(), void *param);
	int		mlx_pixel_put(void *mlx, void *win, int x, int y, int colour);
	void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char* title);
*/

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define PI 3.141592654
# define WIDTH 1918
# define HEIGHT 1080
# define BUFF_SIZE 65536
# define PT_D_ORTO 6
# define PT_D_ISO_H 3

typedef struct s_struct
{
	int					columns;
	int					rows;
	int					**arr;
	int					ret;
	float				iso_x_start;
	float				iso_y_start;
	float				orto_x_start;
	float				orto_y_start;
	float				dx;
	float				dx_default;
	float				dy;
	float				pixx;
	float				pixy;
	unsigned int		pixels;
	unsigned short int	i0;
	unsigned short int	i1;
	short int			min;
	short int			max;
	void				*mlx;
	void				*win;
	short int			k;
	int					columns_temp;
	int					rows_temp;
	char				*legend;
}	t_struct;

typedef struct s_orto
{
	int	pixels;
	int	pixx;
	int	pixy;
	int	d;
	int	columns;
	int	rows;
}	t_orto;

void	read_and_validate(char *buf, char **argv, t_struct *a);
void	count_col_row_ctr(char *buf, t_struct *a);
void	read_map_to_arr(t_struct *a, char *buf);
void	errors(int nb);
int		key_events_orto(int nb, t_struct *a);
void	ortographic(t_struct *a);
void	drawlines_orto_horiz(void *mlx, void *win, t_struct a);
void	drawlines_orto_verti(void *mlx, void *win, t_struct a);
void	isometric(t_struct *a);
void	drawlines_iso_horiz(void *mlx, void *win, t_struct a);
void	drawlines_iso_verti(void *mlx, void *win, t_struct a);
int		colour(t_struct a, int i0, int i1);
void	count_min_max(t_struct *a);

#endif
