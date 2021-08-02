/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:52:31 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 16:28:06 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 1)
		return ;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				ft_error_exit("Error");
			j++;
		}
		i++;
	}
}

int	check_solution(t_stacks *stacks)
{
	size_t	i;

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
