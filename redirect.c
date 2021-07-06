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

static void	choose_operation(t_stacks *s, char *cmd1, char *cmd2)
{
}

static int	check_optimization(t_stacks *s, char **cmd, int i, char *line)
{
	char	needle[4];

	if (ft_strcmp(cmd[i], "sa") == 0)
		needle = "sb\0\0";
	if (ft_strcmp(cmd[i], "sb") == 0)
		needle = "sa\0\0";
	if (ft_strcmp(cmd[i], "ra") == 0)
		needle = "rb\0\0";
	if (ft_strcmp(cmd[i], "rb") == 0)
		needle = "ra\0\0";
	if (ft_strcmp(cmd[i], "rra") == 0)
		needle = "rrb\0";
	if (ft_strcmp(cmd[i], "rrb") == 0)
		needle = "rra\0";
	while (++i < s->elems)
	{

	}
}

void	execute_buf(t_stacks *s)
{
	char	**cmd;
	int	i;
	int	j;
	
	cmd = ft_strsplit(s->buf, "\n");
	i = 0;
	while (i + 1 < s->elems)
	{
		j = 0;
		if (cmd[i][0] == 's' && cmd [i][1] != 's')
			j = check_optimization(s, cmd, i, cmd[i]);
		else if (cmd[i][0] == 'r' && cmd[i][1] != 'r')
			j = check_optimization(s, cmd, i, cmd[i][1]);
		else if (ft_strcmp(cmd[i], "rra") == 0 || ft_strcmp(cmd[i], "rrb") == 0)
			j = check_optimization(s, cmd, i, cmd[i][2]);
		choose_operation(s, commands[i], commands[j]);
		i++;
	}
}

void	redirect_buf(t_stacks *s, int *p, const char *cmd)
{
	if (p == s->a)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			ft_strjoin(s->buf, "sa\n");
		if (ft_strcmp(cmd, "push") == 0)
			ft_strjoin(s->buf, "pa\n");
		if (ft_strcmp(cmd, "rotate") == 0)
			ft_strjoin(s->buf, "ra\n");
		if (ft_strcmp(cmd, "rrotate") == 0)
			ft_strjoin(s->buf, "rra\n");
	}
	else if (p == s->b)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			ft_strjoin(s->buf, "sb\n");
		if (ft_strcmp(cmd, "push") == 0)
			ft_strjoin(s->buf, "pb\n");
		if (ft_strcmp(cmd, "rotate") == 0)
			ft_strjoin(s->buf, "rb\n");
		if (ft_strcmp(cmd, "rrotate") == 0)
			ft_strjoin(s->buf, "rrb\n");
	}
	else if (p == NULL)
		ft_strjoin(s->buf, cmd);
}

void	redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd)
{
	ft_printf("%s\n", cmd);
	f(s);
	if (check_solution(s))
	{
		free_all(NULL, NULL, s);
		exit(0);
	}
}
