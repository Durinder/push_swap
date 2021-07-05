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

void	execute_buf(t_stacks *s)
{
	char	**commands;
	int		i;
	int		j;
	
	commands = ft_strsplit(s->buf, "\n");
	i = 0;
	while (s->elems > 1)
	{
		j = 0;
		if (commands[i][j])
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
