/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:18:35 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/19 20:25:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(int *s)
{
	int	min;

	min = s[0];
	if (min > s[1])
		min = s[1];
	if (min > s[2])
		min = s[2];
	return (min);
}

void		solver_small(t_stacks *s)
{
	int	min;

	if (s->elems == 2)
		redirect(swap_a, s, "sa");
	min = get_min(s->a);
	if ((min == s->a[0] && s->a[1] > s->a[2]) ||
			(min == s->a[1] && s->a[0] < s->a[2]) ||
			(min == s->a[2] && s->a[0] > s->a[1]))
		redirect(swap_a, s, "sa");
	min = get_min(s->a);
	if (min == s->a[1])
		redirect(rotate_a, s, "ra");
	else
		redirect(reverse_rotate_a, s, "rra");
}
