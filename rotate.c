/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:01:26 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 14:11:22 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->a[0];
	i = 0;
	while (i < stacks->a_size - 1 && stacks->a_size)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[i] = tmp;
}

void	rb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->b[0];
	i = 0;
	while (i < stacks->b_size - 1 && stacks->b_size)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = tmp;
}

void	rra(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->a[stacks->a_size - 1];
	i = stacks->a_size - 1;
	while (i)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = tmp;
}

void	rrb(t_stacks *stacks)
{
	int	i;
	int	tmp;

	tmp = stacks->b[stacks->b_size - 1];
	i = stacks->b_size - 1;
	while (i)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = tmp;
}
