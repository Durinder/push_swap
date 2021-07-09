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
	t_stacks	*cpy;
	t_buffer	*head;

	if (check_solution(s))
		return ;
	if (s->elems == 2)
		redirect(sa, s, "sa", 1);
	cpy = copy_stacks(s);
	head = cpy->buffer;
	if (cpy->elems <= 3)
		solver_small(cpy, -1, 0);
	else if (cpy->elems <= 6)
		solver_medium(cpy);
	ft_printf("testi");
	s->buffer = cpy->buffer;
//	free_all(NULL, NULL, cpy);
	ft_printf("\n\nbuf:%s", head->cmd);
	execute_buf(s);
}
