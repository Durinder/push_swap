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

static void	print_buffer(t_buffer *buf)
{
	t_buffer	*cur;
	
	cur = buf;
	while (cur != NULL)
	{
		ft_printf("%s\n", cur->cmd);
		cur = cur->next;
	}
}

void	add_to_last(t_stacks *s, const char *cmd)
{
	t_buffer	*cur;
	t_buffer	*new;

	if (s->buffer == NULL)
	{
		cur = ft_memalloc(sizeof(t_buffer));
		if (cur == NULL)
			ft_error_exit("Error: failed to malloc.");
		cur->cmd = ft_strdup(cmd);
		if (cur->cmd == NULL)
			ft_error_exit("Error: failed to malloc.");
		cur->next = NULL;
		s->buffer = cur;
	}
	else
	{
		new = ft_memalloc(sizeof(t_buffer));
		if (new == NULL)
			ft_error_exit("Error: failed to malloc.");
		new->cmd = ft_strdup(cmd);
		if (new->cmd == NULL)
			ft_error_exit("Error: failed to mallloc.");
		new->next = NULL;
		cur = s->buffer;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
//	ft_printf("%s\n", cmd);
	redirect(NULL, s, cmd, 0);
}

static void	replace(t_buffer *node, const char *replacement, int i)
{
	t_buffer	*cur;
	t_buffer	*del;

	free(node->cmd);
	node->cmd = ft_strdup(replacement);
	if (node == NULL)
		ft_error_exit("Error: failed to malloc");
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
//			ft_printf("look_for:%s, cur->cmd:%s, node:%s, counter:%d\n", look_for, cur->cmd, node->cmd, counter);
			replace(node, replacement, counter);
			return (1);
		}
		if (ft_strcmp(look_for, "sa") == 0 && (ft_strcmp(cur->cmd, "ra") == 0 || \
		ft_strcmp(cur->cmd, "rra") == 0))
			return (0);
		if (ft_strcmp(look_for, "sb") == 0 && (ft_strcmp(cur->cmd, "rb") == 0 || \
		ft_strcmp(cur->cmd, "rrb") == 0))
			return (0);
		if (ft_strcmp(look_for, "ra") == 0 && (ft_strcmp(cur->cmd, "sa") == 0 || \
		ft_strcmp(cur->cmd, "rra") == 0))
			return (0);
		if (ft_strcmp(look_for, "rb") == 0 && (ft_strcmp(cur->cmd, "sb") == 0 || \
		ft_strcmp(cur->cmd, "rrb") == 0))
			return (0);
		if (ft_strcmp(look_for, "rra") == 0 && (ft_strcmp(cur->cmd, "sa") == 0 || \
		ft_strcmp(cur->cmd, "ra") == 0))
			return (0);
		if (ft_strcmp(look_for, "rrb") == 0 && (ft_strcmp(cur->cmd, "sb") == 0 || \
		ft_strcmp(cur->cmd, "rb") == 0))
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
		ft_error_exit("FATAL ERROR");
	ret = 0;
	while (cur->next != NULL)
	{
//		ft_printf("execute_buf:%s\n", cur->cmd);
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
//	ft_printf("%d\n", ret);
	print_buffer(s->buffer);
}
