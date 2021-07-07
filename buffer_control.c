/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:53:23 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 16:30:11 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_last(t_buffer *head, const char *cmd)
{
	t_buffer	*cur;
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		ft_error_exit("Error: failed to malloc.");
	new->cmd = ft_strdup(cmd);
	new->next = NULL;
	if (new == NULL)
		ft_error_exit("Error: failed to mallloc.");
	cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}

static void	replace(t_buffer *node, const char *replacement, int i)
{
	t_buffer	*prev;
	t_buffer	*del;

	free(node->cmd);
	node->cmd = ft_strdup(replacement);
	prev = node;
	while (--i)
	{
		prev = prev->next;
	}
	del = prev->next;
	free(del->cmd);
	prev->next = del->next;
	free(del);
}

static int	check_optimization(t_buffer *node, const char *look_for, const char *replacement)
{
	t_buffer	*cur;
	int			counter;

	cur = node->next;
	counter = 1;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->cmd, "pa") == 0 || ft_strcmp(cur->cmd, "pb") == 0)
			return (-1);
			// CHECK MORE FUCKUPS
		if (ft_strcmp(look_for, cur->cmd) == 0)
		{
			replace(cur, replacement, counter);
			return (1);
		}
		cur = cur->next;
		counter++;
	}
	return (0);
}

void	execute_buf(t_stacks *s)
{
	t_buffer	*cur;

	cur = s->buffer;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->cmd, "sa") == 0)
			check_optimization(cur, "sb", "ss");
		if (ft_strcmp(cur->cmd, "sb") == 0)
			check_optimization(cur, "sa", "ss");
		if (ft_strcmp(cur->cmd, "ra") == 0)
			check_optimization(cur, "rb", "rr");
		if (ft_strcmp(cur->cmd, "rb") == 0)
			check_optimization(cur, "ra", "rr");
		if (ft_strcmp(cur->cmd, "rra") == 0)
			check_optimization(cur, "rrb", "rrr");
		if (ft_strcmp(cur->cmd, "rrb") == 0)
			check_optimization(cur, "rra", "rrr");
	}
}
