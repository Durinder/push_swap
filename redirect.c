/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:16 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/19 18:51:23 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redirect(void (*f)(t_stacks *), t_stacks *s, char *cmd)
{
	ft_printf("%s\n", cmd);
	f(s);
	if (check_solution(s))
	{
		free_all(NULL, NULL, s);
		exit(0);
	}
}
