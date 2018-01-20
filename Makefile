# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proso <proso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/27 13:41:20 by proso             #+#    #+#              #
#    Updated: 2018/01/20 02:26:49 by proso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lemin

SRC = ants.c \
	  find_way.c \
	  free_all.c \
	  get_entry.c \
	  get_rooms.c \
	  get_tubes.c \
	  lemin.c \
	  print_error.c

CC = gcc

FLAGS = -Wall -Werror -Wextra #-fsanitize=address

INCLUDE = Includes/lemin.h

LIB = Libft/libft.a

OBJ = $(addprefix $(DIR_OBJ), $(SRC:.c=.o))

DIR_OBJ = ./OBJ/

DIR_SRC = ./Sources/

all: $(NAME)

$(DIR_OBJ)%.o	:	$(DIR_SRC)%.c $(INCLUDE)
	@$(CC) $(FLAGS) -I./$(INCLUDE) -o $@ -c $<
	@Progress_bar/p_bar_lemin $<
	@sleep 0.05

clr:
	@clear

make_lib:
	@make -C Libft/
	@clear
	@mkdir -p OBJ
	@echo "\x1b[33m\x1b[1mMaking executable... ⏳\x1b[0m"
	@sleep 1

$(NAME): clr make_lib $(OBJ) $(INCLUDE)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB) $(OBJ)
	@sleep 1
	@clear
	@echo "\x1b[32m\x1b[1mExecutable sucessfully created ✓\x1b[0m"

clean:
	@make clean -C Libft/
	@rm -f $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

fclean: clean
	@make fclean -C Libft/
	@rm -f $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_clean:
	@rm -f $(OBJ)
	@echo "\x1b[31m\x1b[1mAll objects deleted ✖\x1b[0m"

local_fclean: local_clean
	@rm -f $(NAME)
	@echo "\x1b[31m\x1b[1mExecutable deleted ✖\x1b[0m"

local_re: local_fclean all

re: fclean all
