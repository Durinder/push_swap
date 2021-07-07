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

/*static int	check_optimization(t_stacks *s, char **cmd, int i, char needle[])
{
	if (ft_strcmp(cmd[i], "sa") == 0)
		needle = ft_strdup("sa\n");
	if (ft_strcmp(cmd[i], "sb") == 0)
		needle = ft_strdup("sb\n");
	if (ft_strcmp(cmd[i], "ra") == 0)
		needle = ft_strdup("ra\n");
	if (ft_strcmp(cmd[i], "rb") == 0)
		needle = ft_strdup("ra\n");
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
		if (ft_strcmp(cmd[i], "sa\n") == 0)
		{
			j = check_optimization(s, cmd, i, "sb\n");
				replace_buf_line(s->buf, i, "ss\n", j);
		}
		else if (cmd[i][0] == 'r' && cmd[i][1] != 'r')
			j = check_optimization(s, cmd, i, cmd[i][1]);
		else if (ft_strcmp(cmd[i], "rra") == 0 || ft_strcmp(cmd[i], "rrb") == 0)
			j = check_optimization(s, cmd, i, cmd[i][2]);
		choose_operation(s, commands[i], commands[j]);
		i++;
	}
}*/

static void	execute_buf(t_stacks *s)
{
	int		i;
	char	*p;

	i = 0;
	while (s->buf_order[i] != '\0');
	{
		if (s->buf_order == 'a')
			p = s->a_buf;
		else if (s->buf_order == 'b')
			p = s->b_buf;
		else if (s->buf_order == 'c')
			p = s->both_buf;
	}
}

void	optimize(t_stacks *s)
{
	
}

static void	write_buf(t_stacks *s, char *p, char *cmd, char c)
{
	ft_strjoin(s->buf_order, c);
	ft_strjoin(p, cmd);
}

void	redirect_buf(t_stacks *s, int *p, const char *cmd)
{
	if (p == s->a)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			write_buf(s, s->a_buf, "sa\n", 'a');
		if (ft_strcmp(cmd, "push") == 0)
			write_buf(s, s->a_buf, "pa\n", 'a');
		if (ft_strcmp(cmd, "rotate") == 0)
			write_buf(s, s->a_buf, "ra\n", 'a');
		if (ft_strcmp(cmd, "rrotate") == 0)
			write_buf(s, s->a_buf, "rra\n", 'a');
	}
	else if (p == s->b)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			write_buf(s, s->b_buf, "sb\n", 'b');
		if (ft_strcmp(cmd, "push") == 0)
			write_buf(s, s->b_buf, "pb\n", 'b');
		if (ft_strcmp(cmd, "rotate") == 0)
			write_buf(s, s->b_buf, "rb\n", 'b');
		if (ft_strcmp(cmd, "rrotate") == 0)
			write_buf(s, s->b_buf, "rrb\n", 'b');
	}
	else if (p == NULL)
		write_buf(s, s->both_buf, cmd, 'c');
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
