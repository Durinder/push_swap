/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:31:54 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 17:30:31 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	command_switch_rotates(const char *cmd, t_stacks *stacks)
{
	if (ft_strcmp(cmd, "rr") == 0)
	{
		rotate_a(stacks);
		rotate_b(stacks);
	}
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate_a(stacks);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate_b(stacks);
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		if (stacks->a_size > 1)
			reverse_rotate_a(stacks);
		if (stacks->b_size > 1)
			reverse_rotate_b(stacks);
	}
	else if (ft_strcmp(cmd, "rra") == 0 && stacks->a_size > 1)
		reverse_rotate_a(stacks);
	else if (ft_strcmp(cmd, "rrb") == 0 && stacks->b_size > 1)
		reverse_rotate_b(stacks);
}

static void	command_switch(const char *cmd, t_stacks *stacks)
{
	if (cmd[0] == 's')
	{
		if (cmd[1] == 's' && cmd[2] == '\0')
		{
			if (stacks->a_size > 1)
				swap_a(stacks);
			if (stacks->b_size > 1)
				swap_b(stacks);
		}
		else if (cmd[1] == 'a' && cmd[2] == '\0' && stacks->a_size > 1)
			swap_a(stacks);
		else if (cmd[1] == 'b' && cmd[2] == '\0' && stacks->b_size > 1)
			swap_b(stacks);
	}
	else if (ft_strcmp(cmd, "pa") == 0 && stacks->b_size > 0)
		push_a(stacks);
	else if (ft_strcmp(cmd, "pb") == 0 && stacks->a_size > 0)
		push_b(stacks);
	command_switch_rotates(cmd, stacks);
}

static int	allowed_commands(char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0 || ft_strcmp(cmd, "sb") == 0 || \
			ft_strcmp(cmd, "ss") == 0 || ft_strcmp(cmd, "pa") == 0 || \
			ft_strcmp(cmd, "pb") == 0 || ft_strcmp(cmd, "ra") == 0 || \
			ft_strcmp(cmd, "rb") == 0 || ft_strcmp(cmd, "rr") == 0 || \
			ft_strcmp(cmd, "rra") == 0 || ft_strcmp(cmd, "rrb") == 0 || \
			ft_strcmp(cmd, "rrr") == 0)
		return (0);
	return (1);
}

void	read_commands(t_stacks *stacks)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	if (stacks->v == 1)
		visualize(stacks);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret == 0)
			break ;
		if (ret == -1)
			ft_error_exit("Error: get_next_line returned -1.");
		if (allowed_commands(line) == 1)
		{
			ft_strdel(&line);
			ft_error_exit("Error: Incorrect operation.");
		}
		command_switch(line, stacks);
		if (stacks->v == 1)
			visualize(stacks);
		ft_strdel(&line);
	}
}
