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

static int	get_min(int *s, int size)
{
	int	min;
	int	i;

	min = s[0];
	i = 0;
	while (size > 0)
	{
		if (min > s[i])
			min = s[i];
		size--;
		i++;
	}
	return (min);
}
/*
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
*/
void	solver_small_dual(t_stacks *s)
{
//	int	a_min;
//	int	b_min;

//	a_min = get_min_dual(s, 0);
//	b_min = get_min_dual(s, 1);
	solver_small_a(s);
	solver_small_b(s);
}

void	solver_small_b(t_stacks *s)
{
	int		*p;
	int		min;

	min = get_min(s->b, s->b_size);
	p = s->b;
	if (s->b_size == 2 && p[0] < p[1])
	{
		redirect_buf(s, p, "switch");
		return ;
	}
	if ((min == p[0] && p[1] < p[2]) || \
			(min == p[1] && p[0] > p[2]) || \
			(min == p[2] && p[0] < p[1]))
			redirect_buf(s, p, "switch");
	if (min == p[0])
		redirect_buf(s, p, "rotate");
	else if (min == p[1])
		redirect_buf(s, p, "rrotate");
}

void	solver_small_a(t_stacks *s)
{
	int		*p;
	int		min;

	min = get_min(s->a, s->a_size);
	p = s->a;
	if ((min == p[0] && p[1] > p[2]) || \
			(min == p[1] && p[0] < p[2]) || \
			(min == p[2] && p[0] > p[1]))
			redirect_buf(s, p, "switch");
	if (min == p[1])
		redirect_buf(s, p, "rotate");
	else if (min == p[2])
		redirect_buf(s, p, "rrotate");
}
