# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 18:12:05 by jhallama          #+#    #+#              #
#    Updated: 2021/07/07 16:33:22 by jhallama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(CHECKER) $(PUSH_SWAP)

CHECKER = checker
CHECKER_SRC = checker.c visualizer.c init_stacks.c read_commands.c check_solution.c swap.c push.c rotate.c operate_both.c free_all.c
CHECKER_HEADERS = -I checker.h
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

PUSH_SWAP = push_swap
PUSH_SWAP_SRC = push_swap.c visualizer.c init_stacks.c check_solution.c redirect.c swap.c push.c rotate.c operate_both.c free_all.c solver.c solver_small.c solver_medium.c solver_high.c solver_loop.c make_copy.c buffer_control.c
PUSH_SWAP_HEADERS = -I push_swap.h
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

LIBRARY = libft/ft_printf/libftprintf.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re 

all: $(NAME)

$(LIBRARY):
	@make -C libft/ft_printf/

$(CHECKER): $(LIBRARY)
	@gcc $(FLAGS) -c $(CHECKER_SRC)
	@gcc $(FLAGS) -o $(CHECKER) $(CHECKER_OBJ) $(CHECKER_HEADERS) $(LIBRARY)
	@echo "Made checker"

$(PUSH_SWAP): $(LIBRARY)
	@gcc $(FLAGS) -c $(PUSH_SWAP_SRC)
	@gcc $(FLAGS) -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(PUSH_SWAP_HEADERS) $(LIBRARY)
	@echo "Made push_swap"

clean:
	@make -C libft/ft_printf/ clean
	@rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@echo "Cleaned root .o files"

fclean: clean
	@make -C libft/ft_printf/ fclean
	@rm -f $(CHECKER) $(PUSH_SWAP)
	@echo "Cleaned root libraries and binary files"

re: fclean all
