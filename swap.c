/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:54:53 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 17:37:25 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_stacks *stacks)
{
	int	tmp;
	
	tmp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = tmp;
}

void	swap_b(t_stacks *stacks)
{
	int	tmp;
	
	tmp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = tmp;
}
