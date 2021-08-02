/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:18:31 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 16:18:35 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_stacks *stacks)
{
	size_t		i;
	t_buffer	*tmp;

	i = 0;
	if (stacks)
	{
		if (stacks->buffer)
		{
			while (stacks->buffer != NULL)
			{
				tmp = stacks->buffer;
				stacks->buffer = stacks->buffer->next;
				free(tmp->cmd);
				free(tmp);
			}
			free(stacks->buffer);
		}
		free(stacks->a);
		free(stacks->b);
		free(stacks);
	}
}
