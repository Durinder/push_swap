/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:33:31 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 15:29:50 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

void		solver(t_stacks *s);
t_stacks	*copy_stacks(t_stacks *src);
void		solver_small_a(t_stacks *s);
void		solver_small_dual(t_stacks *s);
void		solver_medium(t_stacks *s);
void		radix_sort(t_stacks *s);
void		sort_array(int **array, int elems);
void		redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd,
int print);
void		redirect_buf(t_stacks *s, int *p, const char *cmd);
void		add_to_last(t_stacks *s, const char *cmd);
void		execute_buf(t_stacks *s);
void		visualize(t_stacks *stacks);
int			check_sorted_offset(t_stacks *slim, int *p, int elems);
#endif
