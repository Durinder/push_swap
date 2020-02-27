/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:39:50 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 17:48:13 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	visualize(t_stacks *stacks)
{
	size_t	i;

	ft_printf("STACK_A  |  STACK_B\n");
	i = 0;
	while (i < stacks->elems)
	{
		ft_printf("%-9d|%9d\n", stacks->a[i], stacks->b[i]);
		i++;
	}
}
