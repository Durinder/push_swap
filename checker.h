/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:28:21 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 17:17:35 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stacks {
	int		*a;
	int		*b;
	int		elems;
	int		a_size;
	int		b_size;
	char	v;
	char	*buf;
}	t_stacks;

int		*init(int argc, char **input);
int		count(char **input, char n);
void	init_b(t_stacks *stacks);
void	read_commands(t_stacks *stacks);
int		check_solution(t_stacks *stacks);
void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);
void	rotate_ab(t_stacks *stacks);
void	reverse_rotate_ab(t_stacks *stacks);
void	visualize(t_stacks *stacks);
char	v_check(char ***input, char n);
void	check_duplicates(int *stack, int size);
void	free_all(char *message, char **input, t_stacks *stacks);
#endif
