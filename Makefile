# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:51:25 by gsmereka          #+#    #+#              #
#    Updated: 2023/01/02 13:19:58 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap 

NAME_B			=	checker

HEADERS			=	./headers/push_swap.h ./headers/objects.h ./headers/utils.h 

HEADERS_BONUS	=	./headers/checker.h ./headers/objects.h ./headers/utils.h 

CFLAGS			=	-Wall -Wextra -Werror
# CFLAGS			=

OBJ_DIR			=	./obj

SRC_DIR			=	src

BONUS_DIR		=	src_bonus

UTILS_DIR		=	utils

LIST_UTILS_DIR	=	list_utils

SRC				=	push_swap.c check_args.c set_numbers.c sort_utils.c\
					set_binary_values.c init_sort.c sort_small_list.c sort_big_list.c\
					sort_average_list.c finalize.c initialize.c set_stack.c \

SRC_B			=	check_args.c finalize.c initialize.c set_numbers.c \
					set_stack.c \
					checker.c get_next_line_clean.c \

UTILS			=	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c \
					ft_substr.c ft_calloc.c ft_strlcpy.c ft_bzero.c \
					ft_strncmp.c ft_split.c ft_isdigit.c \
					ft_printf.c ft_itoa.c ft_itohex.c ft_toupper.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_utoa.c \

LIST_UTILS		=	ft_push.c ft_swap.c ft_reverse_rotate.c ft_rotate.c \
					list_utils_1.c list_utils_2.c \

OBJ				=	$(addprefix $(OBJ_DIR)/, $(addprefix $(SRC_DIR)/, $(SRC:.c=.o)))

OBJ_B			=	$(addprefix $(OBJ_DIR)/, $(addprefix $(BONUS_DIR)/, $(SRC_B:.c=.o)))

OBJ_UTILS		=	$(addprefix $(OBJ_DIR)/, $(addprefix $(UTILS_DIR)/, $(UTILS:.c=.o)))

OBJ_LIST_U		=	$(addprefix $(OBJ_DIR)/, $(addprefix $(LIST_UTILS_DIR)/, $(LIST_UTILS:.c=.o)))

all: $(NAME)

bonus: $(NAME_B)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(BONUS_DIR) $(OBJ_DIR)/$(LIST_UTILS_DIR) $(OBJ_DIR)/$(UTILS_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ) $(OBJ_UTILS) $(OBJ_LIST_U)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_UTILS) $(OBJ_LIST_U)

$(NAME_B): $(HEADERS_BONUS) $(OBJ_B) $(OBJ_UTILS) $(OBJ_LIST_U)
	cc $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(OBJ_UTILS) $(OBJ_LIST_U)

git: fclean
	git add . && clear && git status

clear: $(NAME) clean
	clear

clear_bonus: $(NAME_B) clean
	clear

clean:
	rm -rf $(OBJ) $(OBJ_B) $(OBJ_UTILS) $(OBJ_LIST_U) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re clear clear_bonus .c.o git
