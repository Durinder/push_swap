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
