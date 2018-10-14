#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatvien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/06 20:11:35 by lmatvien          #+#    #+#              #
#    Updated: 2018/07/21 11:07:03 by lmatvien         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
NAME1 = libft_mini.a

FLAGS  += -Wall -Werror -Wextra
FLAG_HEADER_MLX  += -I ./src/minilibx/
FDF_HEADER += ./includes/
FT_LIB_MINI_HDR += ./src/libft_mini/
FLAG_HADER_FT_PRINTF += ./src/ft_printf/includes/
FT_PRINTF_DIR += ./src/ft_printf/
MLX_LIB += ./src/minilibx/ -lmlx -framework OpenGL -framework AppKit
FT_PRINTF += ./src/ft_printf/libftprintf.a

CFILES = 	main.c \
			open_file.c \
			error_description.c \
			error_description_s.c \
			list_manipulations.c \
			finder.c \
			memory_destroyer.c \
			create_image.c \
			imager.c \
			algorithm_bre.c \
			algorithm_bre_v.c \
			keyboard_affect.c \
			keyboard_control.c \
			color_tools.c \
			keyboard_zoom.c \
			pctr_rtt.c  \

LIBFILE = 	ft_strchr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strlen.c \
			ft_strnlen.c \
			ft_strnew.c \
			ft_strjoin.c \
			ft_strstr.c \
			ft_memset.c \
			ft_atoi_base.c \
			ft_strncat.c \
			ft_strcat.c \
			get_next_line.c \
			ft_strsplit.c \
			ft_isdigit.c \
			ft_atoi.c \
			ft_swap.c \

FDF_SRC = $(addprefix ./src/, $(CFILES))
FT_LIB_SRC =  $(addprefix ./src/libft_mini/, $(LIBFILE))

OBJ1 = $(FT_LIB_SRC:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ1): %.o: %.c 
	@gcc -c $(FLAGS) $(HDR)$< -o $@

$(NAME): $(OBJ1)
	@ar rcs ./src/libft_mini/$(NAME1) $(OBJ1)
	@echo "\033[35;1m>>>Created FT_LIB_MINI\033[0m"
	@make -C ./src/ft_printf/
	@gcc -o $(NAME) $(FLAG_HEADER_MLX) -I $(FDF_HEADER) -I $(FT_LIB_MINI_HDR) -I $(FLAG_HADER_FT_PRINTF) $(FT_PRINTF) -L $(MLX_LIB) $(FT_LIB_MINI_HDR)libft_mini.a $(FDF_SRC)
	@echo "\033[31;1m>>>Complete\033[0m"
clean:
	@/bin/rm -f $(NAME)
	 @/bin/rm -f $(OBJ1)
	@echo "\033[35;1m>>>Removed FT_LIB_MINI OBJ Files\033[0m"
	@make clean -C ./src/ft_printf/

fclean: clean
	@/bin/rm -rf ./src/libft_mini/$(NAME1)
	@echo "\033[35;1m>>>Removed FT_LIB_MINI OBJ Files and library\033[0m"
	@make fclean -C ./src/ft_printf/

re: fclean all