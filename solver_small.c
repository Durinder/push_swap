/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:18:35 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 15:17:57 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(int *s, int tmp)
{
	int	min;
	int	i;

	min = s[0];
	i = 0;
	while (tmp > 0)
	{
		tmp--;
		i++;
		if (min > s[i])
			min = s[i];
	}
	return (min);
}

static int	get_min_dual(t_stacks *s, int which)
{
	int		min;
	size_t	tmp;

	min = 0;
	if (which == 0)
	{
		tmp = s->a_size;
		min = get_min(s->a, tmp);
	}
	else if (which == 1)
	{
		tmp = s->b_size;
		min = get_min(s->b, tmp);
	}
	else
		ft_error_exit("Error: no stack defined.");
	return (min);
}

void	solver_small_dual(t_stacks *s)
{
	int	a_min;
	int	b_min;

	a_min = get_min_dual(s, 0);
	b_min = get_min_dual(s, 1);
	solver_small(s, 0, a_min);
	solver_small(s, 1, b_min);
}

void	solver_small(t_stacks *s, int which, int min)
{
	int			*p;

	p = NULL;
	if (which == -1)
		min = get_min(s->a, s->a_size);
	else if (which == 0)
		p = s->a;
	else if (which == 1)
		p = s->b;
	else
		ft_error_exit("Error: no stack defined.");
	if ((min == p[0] && p[1] > p[2]) || \
			(min == p[1] && p[0] < p[2]) || \
			(min == p[2] && p[0] > p[1]))
		redirect_buf(s, p, "switch");
	if (min == p[1])
		redirect_buf(s, p, "rotate");
	else
		redirect_buf(s, p, "rrotate");
}
