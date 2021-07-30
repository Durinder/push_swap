/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:03:44 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 16:48:43 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solver(t_stacks *s)
{
	if (check_solution(s))
		return ;
	if (s->elems == 2)
		redirect(sa, s, "sa", 1);
	if (s->elems <= 3)
		solver_small_a(s);
	else if (s->elems <= 6)
		solver_medium(s);
	else if (s->elems > 6)
		radix_sort(s);
	execute_buf(s);
}
