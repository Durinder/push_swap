# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 13:26:51 by jhallama          #+#    #+#              #
#    Updated: 2020/02/25 14:13:02 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(CHECKER) $(PUSH_SWAP)

CHECKER = checker
CHECKER_SRC = checker.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
CHECKER_HEADERS = -I checker.h

PUSH_SWAP = push_swap
PUSH_SWAP_SRC = push_swap.c
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)
PUSH_SWAP_HEADERS = -I push_swap.h

LIBFT = libft/libft.a

FT_PRINTF = libft/ft_printf/ft_printf.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all: $(NAME)

$(LIBFT):
	@make -C libft/

$(FT_PRINTF):
	@make -C libft/ft_printf/

$(CHECKER): $(LIBFT) $(FT_PRINTF)
	@gcc $(FLAGS) -c $(CHECKER_SRC)
	@gcc $(FLAGS) -o $(CHECKER) $(CHECKER_OBJ) $(CHECKER_HEADERS) $(LIBFT) $(FT_PRINTF)
	@echo "Made checker"

$(PUSH_SWAP): $(LIBFT) $(FT_PRINTF)
	@gcc $(FLAGS) -c $(PUSH_SWAP_SRC)
	@gcc $(FLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(PUSH_SWAP_HEADERS) $(LIBFT) $(FT_PRINTF)
	@echo "Made push_swap"

clean:
	@make -C libft/ clean
	@make -C libft/ft_printf/ clean
	@rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@echo "Cleaned .o files"

fclean: clean
	@make -C libft/ fclean
	@make -C libft/ft_printf/ fclean
	@rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "Cleaned binary files"

re: fclean all
