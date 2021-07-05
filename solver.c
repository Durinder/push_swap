/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:03:44 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/19 21:02:30 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stacks *s)
{
	t_stacks	*cpy;

	if (check_solution(s))
		return ;
	if (s->elems == 2)
		redirect(swap_a, s, "sa");
	cpy = copy_stacks(s);
	if (s->elems <= 3)
		solver_small(cpy, -1, 0);
	else if (s->elems <= 6)
		solver_medium(cpy);
	execute_buf(cpy);
}
