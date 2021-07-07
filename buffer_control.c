/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:53:23 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 13:50:03 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_last(t_buffer *head, char *cmd)
{
	t_buffer	*cur;
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	new->cmd = ft_strdup(cmd);
	new->next = NULL;
	if (new == NULL)
		ft_error_exit("Error: failed to mallloc.");
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}
