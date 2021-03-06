/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:54:53 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 14:11:31 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = tmp;
}

void	sb(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = tmp;
}
