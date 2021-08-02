/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:28:21 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 16:35:21 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_buffer {
	char			*cmd;
	struct s_buffer	*next;
}	t_buffer;

typedef struct s_stacks {
	struct s_buffer	*buffer;
	int				*a;
	int				*b;
	size_t			elems;
	size_t			a_size;
	size_t			b_size;
	char			v;
}	t_stacks;

t_stacks	*init_stacks(char **input, int argc, char **argv);
void		read_commands(t_stacks *stacks);
int			check_solution(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		visualize(t_stacks *stacks);
char		v_check(char ***input, const char n);
void		check_duplicates(int *stack, int size);
void		free_stacks(t_stacks *stacks);
#endif