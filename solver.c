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
//	t_stacks	*cpy;

	if (check_solution(s))
		return ;
	if (s->elems == 2)
		redirect(sa, s, "sa", 1);
//	cpy = copy_stacks(s);
	if (s->elems <= 3)
		solver_small_a(s);
	else if (s->elems <= 6)
		solver_medium(s);
//	ft_printf("testi");
//	*s->buffer = *cpy->buffer;
//	s->buffer = cpy->buffer;
//	ft_printf("cpy->buffer->cmd: %s", cpy->buffer->cmd);
//	ft_printf("s->buffer->cmd: %s", s->buffer->cmd);
//	free_all(NULL, NULL, cpy);
	execute_buf(s);
}
