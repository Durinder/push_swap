/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:52:31 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 15:30:24 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

int	check_sorted_offset(t_stacks *slim, int *p, int elems) //FIX!!!
{
	int	i;
	int	stop;

	i = 0;
	while(p[i] != INT_MIN)
		i++;
	stop = i;
	if (p == slim->b)
	{
		i = 0;
		stop = 0;
		while (++i < elems)
		{
			if (p[i] > p[i - 1])
				stop = i;
		}
		i = stop;
	}
//	ft_printf("%d", stop);
	while (1)
	{
		if (i + 1 == elems)
		{
			if ((p == slim->a && p[i] > p[0]) || (p == slim->b && p[i] < p[0]))
				return (-1);
			if (stop == 0)
				return (0);
			i = 0;
		}
		else if ((p == slim->a && p[i] > p[i + 1]) || (p == slim->b && p[i] < p[i + 1])) // NOT WORKING!!!
			return (-1);
		i++;
		if (i == stop)
			return (i);
	}
	return (i);
}

int	check_solution(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->elems - 1)
	{
		if (stacks->a[i] < stacks->a[i + 1])
			i++;
		else
			return (0);
	}
	if (i == stacks->elems - 1 && stacks->b_size == 0)
		return (1);
	return (0);
}
