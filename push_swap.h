/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:33:31 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/19 20:23:01 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

enum operations {sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

typedef struct s_buffer {
    char    *a;
    char    *b;
}   t_buffer;

void	solver(t_stacks *s);
t_stacks	*copy_stacks(t_stacks *src);
void	solver_small(t_stacks *s, int which, int min);
void	solver_small_dual(t_stacks *s);
void	solver_medium(t_stacks *s);
void	redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd);
void	redirect_buf(t_stacks *s, int *p, const char *cmd);
void	execute_buf(t_stacks *s);
void	visualize(t_stacks *stacks);
#endif
