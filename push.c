/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:57:44 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 15:09:25 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_size)
	{
		stacks->a[stacks->a_size - i] = stacks->a[stacks->a_size - i - 1];
		i++;
	}
	stacks->a[0] = stacks->b[0];
	i = 0;
	while (i < stacks->b_size)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = 0;
	stacks->a_size++;
	stacks->b_size--;
}

void	pb(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->b_size)
	{
		stacks->b[stacks->b_size - i] = stacks->b[stacks->b_size - i - 1];
		i++;
	}
	stacks->b[0] = stacks->a[0];
	i = 0;
	while (i < stacks->a_size)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[i] = 0;
	stacks->b_size++;
	stacks->a_size--;
}
