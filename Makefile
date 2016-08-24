#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smarie-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/24 14:11:04 by smarie-c          #+#    #+#              #
#    Updated: 2016/08/24 14:11:58 by smarie-c         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = bresenham.c \
		create_rot_matrix.c \
		down_rot.c \
		draw.c \
		event_scale.c \
		ft_event.c \
		ft_key.c \
		ft_read.c \
		actu_map.c \
		main.c \
		matrix.c \
		move_event.c \
		up_rot.c \
		utils.c \
		tools.c
HEAD = fdf.h

MLX = minilibx_macos

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft/includes -I /usr/X11/include -I /usr/include

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@gcc $(FLAGS) $(INCLUDES) -c $(SRC)
	@gcc $(OBJ) -L libft -lft -L $(MLX) -lmlx -framework OpenGl -framework AppKit -o $(NAME)

clean :
	@make -C ./libft clean
	@rm -f $(OBJ)

fclean : clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all
