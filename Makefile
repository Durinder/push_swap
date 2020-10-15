# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 16:54:57 by jhallama          #+#    #+#              #
#    Updated: 2020/10/15 16:54:59 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(CHECKER) $(PUSH_SWAP)

CHECKER = checker
CHECKER_SRC = checker.c init_stacks.c read_commands.c check_solution.c swap.c push.c rotate.c visualizer.c free_all.c
CHECKER_HEADERS = -I checker.h
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP = push_swap
PUSH_SWAP_SRC = push_swap.c init_stacks.c
PUSH_SWAP_HEADERS = -I push_swap.h
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

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
	@gcc $(FLAGS) -o $(CHECKER) $(CHECKER_OBJ) $(CHECKER_HEADERS) $(FT_PRINTF) $(LIBFT)
	@echo "Made checker"

$(PUSH_SWAP): $(LIBFT) $(FT_PRINTF)
	@gcc $(FLAGS) -c $(PUSH_SWAP_SRC)
	@gcc $(FLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(PUSH_SWAP_HEADERS) $(FT_PRINTf) $(LIBFT)
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
	@echo "Cleaned libraries and binary files"

re: fclean all
