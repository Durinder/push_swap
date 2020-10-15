/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:54:24 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/15 16:54:26 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(char *message, char **input, t_stacks *stacks)
{
	size_t	i;

	i = 0;
	if (input)
	{
		while (input[i])
			ft_strdel(&input[i++]);
		free(input);
	}
	if (stacks)
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
	}
	if (message)
		ft_error_exit(message);
}
