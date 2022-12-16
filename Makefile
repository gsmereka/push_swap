# **************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:51:39 by gsmereka          #+#    #+#              #
#    Updated: 2022/11/28 09:47:39 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap 

NAME_B			=	push_swap_bonus

HEADERS			=	./headers/push_swap.h ./headers/objects.h ./headers/utils.h 

HEADERS_BONUS	=	./headers/push_swap_bonus.h ./headers/objects_bonus.h ./headers/utils.h 

CFLAGS			=	
# CFLAGS			=	-Wall -Wextra -Werror

SRC				=	./src/push_swap.c ./src/check_args.c ./src/set_numbers.c \
					./src/finalize.c ./src/initialize.c ./src/set_stack.c 

SRC_B			=	

UTILS			=	./utils/ft_strchr.c ./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
					./utils/ft_substr.c ./utils/ft_calloc.c ./utils/ft_strlcpy.c ./utils/ft_bzero.c \
					./utils/ft_strncmp.c ./utils/ft_split.c ./utils/ft_isdigit.c \
					./utils/ft_printf.c ./utils/ft_itoa.c ./utils/ft_itohex.c ./utils/ft_toupper.c \
					./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_utoa.c \
					./utils_list/list_utils_1.c ./utils_list/list_utils_2.c

OBJ				=	$(SRC:.c=.o)

OBJ_B			=	$(SRC_B:.c=.o)

OBJ_UTILS		=	$(UTILS:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_UTILS)

$(NAME_B): $(HEADERS_BONUS) $(OBJ_B) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(OBJ_UTILS)

clear: $(NAME) clean
	clear

clear_bonus: $(NAME_B) clean
	clear

clean:
	rm -f $(OBJ) $(OBJ_B) $(OBJ_UTILS)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re clear clear_bonus .c.o
