/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:16 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 14:56:37 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redirect_buf(t_stacks *s, int *p, const char *cmd)
{
	if (p == s->a)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			add_to_last(s->buffer, "sa");
		if (ft_strcmp(cmd, "push") == 0)
			add_to_last(s->buffer, "pa");
		if (ft_strcmp(cmd, "rotate") == 0)
			add_to_last(s->buffer, "ra");
		if (ft_strcmp(cmd, "rrotate") == 0)
			add_to_last(s->buffer, "rra");
	}
	else if (p == s->b)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			add_to_last(s->buffer, "sb");
		if (ft_strcmp(cmd, "push") == 0)
			add_to_last(s->buffer, "pb");
		if (ft_strcmp(cmd, "rotate") == 0)
			add_to_last(s->buffer, "rb");
		if (ft_strcmp(cmd, "rrotate") == 0)
			add_to_last(s->buffer, "rrb");
	}
	else if (p == NULL)
		add_to_last(s->buffer, cmd);
}

static int	get_pointer(const char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		return (0);
	else if (ft_strcmp(cmd, "sb") == 0)
		return (1);
	else if (ft_strcmp(cmd, "ss") == 0)
		return (2);
	else if (ft_strcmp(cmd, "pa") == 0)
		return (3);
	else if (ft_strcmp(cmd, "pb") == 0)
		return (4);
	else if (ft_strcmp(cmd, "ra") == 0)
		return (5);
	else if (ft_strcmp(cmd, "rb") == 0)
		return (6);
	else if (ft_strcmp(cmd, "rr") == 0)
		return (7);
	else if (ft_strcmp(cmd, "rra") == 0)
		return (8);
	else if (ft_strcmp(cmd, "rrb") == 0)
		return (9);
	else if (ft_strcmp(cmd, "rrr") == 0)
		return (10);
	ft_error_exit("Error: invalid command.");
	exit(0);
}

void	redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd)
{
	ft_printf("%s\n", cmd);
	if (f != NULL)
		f(s);
	else
		redirect((void *)g_operations[get_pointer(cmd)], s, cmd);
	if (check_solution(s))
	{
		free_all(NULL, NULL, s);
		exit(0);
	}
}
