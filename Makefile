# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturto <tturto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 18:51:47 by tturto            #+#    #+#              #
#    Updated: 2022/08/31 11:26:26 by tturto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
INCLUDES =	-I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
LIBFT = make -C ./libft/
LIBFTA = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SOURCES =	main.c errors.c key_events_orto.c read_and_validate.c count_col_row_ctr.c read_map_to_arr.c \
			ortographic.c drawlines_orto_horiz.c drawlines_orto_verti.c \
			isometric.c drawlines_iso_horiz.c drawlines_iso_verti.c \
			colour.c count_min_max.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): 
	@ $(LIBFT)
	@ gcc -c $(FLAGS) $(SOURCES)	
	@ gcc -o $(NAME) $(OBJECTS) $(LIBFTA) $(INCLUDES) 
	@echo "Compilation has been completed"

clean:
	@ rm -f $(OBJECTS)
	@ $(LIBFT) clean
	@ echo "'clean' has been completed"

fclean: clean
	@ rm -f $(NAME)
	@ $(LIBFT) fclean
	@ echo "'fclean' has been completed"

re: fclean all
