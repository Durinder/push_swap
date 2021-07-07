/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:26:59 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 15:09:08 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
