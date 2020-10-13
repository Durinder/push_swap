/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:28:21 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 18:28:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct	s_stacks {
	int		*a;
	int		*b;
//	int		*c;
	size_t	elems;
	size_t	a_size;
	size_t	b_size;
	char	v;
}				t_stacks;

int				*init(int argc, char **input);
size_t			count_elems(char **input, char n);
void			init_b(t_stacks *stacks);
void			read_commands(t_stacks *stacks);
int				check_solution(t_stacks *stacks);
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);
void			rotate_a(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			reverse_rotate_a(t_stacks *stacks);
void			reverse_rotate_b(t_stacks *stacks);
void			visualize(t_stacks *stacks);
char			v_check(char ***input, char n);
void			check_duplicates(int *stack, size_t size);
//void			free_stacks(t_stacks *stacks);
#endif
