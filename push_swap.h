/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:33:31 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 14:45:05 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

void	(*g_operations[11])(t_stacks *stacks) = {
	sa, sb, ss, ra, rb, rr, rra, rrb, rrr};
void		solver(t_stacks *s);
t_stacks	*copy_stacks(t_stacks *src);
void		solver_small(t_stacks *s, int which, int min);
void		solver_small_dual(t_stacks *s);
void		solver_medium(t_stacks *s);
void		redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd);
void		redirect_buf(t_stacks *s, int *p, const char *cmd);
void		add_to_last(t_buffer *head, const char *cmd);
void		execute_buf(t_stacks *s);
void		visualize(t_stacks *stacks);
#endif
