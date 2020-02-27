/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:31:54 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 18:35:39 by jhallama         ###   ########.fr       */
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

void		read_commands(t_stacks *stacks)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	visualize(stacks);
	while ((ret = get_next_line(0, &line) > 0))
	{
		command_switch(line, stacks);
		visualize(stacks);
		ft_strdel(&line);
	}
}
