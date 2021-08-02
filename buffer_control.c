/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:53:23 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 13:48:15 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_last(t_stacks *s, const char *cmd)
{
	t_buffer	*cur;
	t_buffer	*new;

	new = ft_memalloc(sizeof(t_buffer));
	if (new == NULL)
		ft_error_exit("Error");
	new->cmd = ft_strdup(cmd);
	if (new->cmd == NULL)
		ft_error_exit("Error");
	new->next = NULL;
	if (s->buffer == NULL)
		s->buffer = new;
	else
	{
		cur = s->buffer;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	redirect(NULL, s, cmd, 0);
}

static void	replace(t_buffer *node, const char *replacement, int i)
{
	t_buffer	*cur;
	t_buffer	*del;

	free(node->cmd);
	node->cmd = ft_strdup(replacement);
	if (node == NULL)
		ft_error_exit("Error");
	cur = node;
	while (i > 1)
	{
		cur = cur->next;
		i--;
	}
	del = cur->next;
	free(del->cmd);
	cur->next = del->next;
	free(del);
}

static int	conditions(t_buffer *cur, const char *look_for)
{
	if (!ft_strcmp(look_for, "sa") && (!ft_strcmp(cur->cmd, "ra") || \
	!ft_strcmp(cur->cmd, "rra")))
		return (1);
	if (!ft_strcmp(look_for, "sb") && (!ft_strcmp(cur->cmd, "rb") || \
	!ft_strcmp(cur->cmd, "rrb")))
		return (1);
	if (!ft_strcmp(look_for, "ra") && (!ft_strcmp(cur->cmd, "sa") || \
	!ft_strcmp(cur->cmd, "rra")))
		return (1);
	if (!ft_strcmp(look_for, "rb") && (!ft_strcmp(cur->cmd, "sb") || \
	!ft_strcmp(cur->cmd, "rrb")))
		return (1);
	if (!ft_strcmp(look_for, "rra") && (!ft_strcmp(cur->cmd, "sa") || \
	!ft_strcmp(cur->cmd, "ra")))
		return (1);
	if (!ft_strcmp(look_for, "rrb") && (!ft_strcmp(cur->cmd, "sb") || \
	!ft_strcmp(cur->cmd, "rb")))
		return (1);
	return (0);
}

static int	check_optimization(t_buffer *node, const char *look_for,
		const char *replacement)
{
	t_buffer	*cur;
	int			counter;

	cur = node;
	counter = 0;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->cmd, "pa") == 0 || ft_strcmp(cur->cmd, "pb") == 0)
			return (0);
		if (ft_strcmp(look_for, cur->cmd) == 0)
		{
			replace(node, replacement, counter);
			return (1);
		}
		if (conditions(cur, look_for))
			return (0);
		cur = cur->next;
		counter++;
	}
	return (0);
}

void	execute_buf(t_stacks *s)
{
	t_buffer	*cur;
	int			ret;

	cur = s->buffer;
	if (cur == NULL)
		ft_error_exit("Error");
	ret = 0;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->cmd, "sa") == 0)
			ret += check_optimization(cur, "sb", "ss");
		if (ft_strcmp(cur->cmd, "sb") == 0)
			ret += check_optimization(cur, "sa", "ss");
		if (ft_strcmp(cur->cmd, "ra") == 0)
			ret += check_optimization(cur, "rb", "rr");
		if (ft_strcmp(cur->cmd, "rb") == 0)
			ret += check_optimization(cur, "ra", "rr");
		if (ft_strcmp(cur->cmd, "rra") == 0)
			ret += check_optimization(cur, "rrb", "rrr");
		if (ft_strcmp(cur->cmd, "rrb") == 0)
			ret += check_optimization(cur, "rra", "rrr");
		cur = cur->next;
	}
}
