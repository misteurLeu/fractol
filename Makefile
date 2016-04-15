# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 23:53:34 by jleu              #+#    #+#              #
#    Updated: 2016/04/08 08:35:08 by jleu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/fractol.c						\
	  srcs/ft_images.c						\
	  srcs/ft_put_pixel_to_image.c			\
	  srcs/ft_new_complex.c					\
	  srcs/ft_quit.c						\
	  srcs/ft_zoom.c						\
	  srcs/ft_random.c						\
	  srcs/ft_resize.c						\
	  srcs/ft_getcomplex.c					\
	  srcs/ft_write_param.c					\
	  srcs/ft_hook.c						\
	  srcs/ft_putline.c						\
	  srcs/ft_arbres.c						\
	  srcs/ft_reset.c						\
	  srcs/ft_mouse_move_hook.c				\

OBJ = fractol.o								\
	  ft_images.o							\
	  ft_put_pixel_to_image.o				\
	  ft_new_complex.o						\
	  ft_quit.o								\
	  ft_zoom.o								\
	  ft_random.o							\
	  ft_resize.o							\
	  ft_getcomplex.o						\
	  ft_write_param.o						\
	  ft_hook.o								\
	  ft_putline.o							\
	  ft_arbres.o							\
	  ft_reset.o							\
	  ft_mouse_move_hook.o						\

NAME = fractol

INCPATH =	-I ./includes					\

FLAGS = -Wall								\
		-Wextra								\
		-Werror								\
		-O3									\

LIBS = libft/libft.a						\
	   -lmlx								\
	   -framework OpenGL					\
	   -framework Appkit					\

all: $(NAME)

$(OBJ):
	cd libft/ && $(MAKE)
	cd ../
	gcc $(FLAGS) -c $(SRC) $(INCPATH)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBS) $(INCPATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : re clean fclean all
