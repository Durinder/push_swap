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

	ft_printf("STACK_A     |     STACK_B\n");
	i = 0;
	while (i < stacks->a_size || i < stacks->b_size)
	{
		if (stacks->a_size > i)
			ft_printf("%-12d", stacks->a[i]);
		else
			ft_printf("            ");
		if (stacks->b_size > i)
			ft_printf("%13d\n", stacks->b[i]);
		else
			ft_printf("\n");
		i++;
	}
}
