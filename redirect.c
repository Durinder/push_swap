/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:16 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 14:05:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_buf(t_stacks *s)
{
	t_buffer	*cur;
	t_buffer	*check;

	cur = s->buffer;
	while (cur->next != NULL)
	{
		redirect(NULL, s, cur->cmd);
	}
}

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

void	redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd)
{
	void	(*operations[11])(t_stacks *stacks);

	operations[0] = sa;
	operations[1] = sb;
	operations[2] = ss;
	operations[3] = pa;
	operations[4] = pb;
	operations[5] = ra;
	operations[6] = rb;
	operations[7] = rr;
	operations[8] = rra;
	operations[9] = rrb;
	operations[10] = rrr;
	ft_printf("%s\n", cmd);
	if (f != NULL)
		f(s);
	else if (ft_strcmp(cmd, "sa") == 0)
		swap_a(s);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap_b(s);
	else if (ft_strcmp(cmd, "ss") == 0)
		swap_ab(s);
	else if (ft_strcmp(cmd, "pa") == 0)
		push_a(s);
	else if (ft_strcmp(cmd, "pb") == 0)
		push_b(s);
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate_a(s);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate_b(s);
	else if (ft_strcmp(cmd, "rr") == 0)
		rotate_ab(s);
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate_a(s);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate_b(s);
	else if (ft_strcmp(cmd, "rrr") == 0)
		reverse_rotate_ab(s);
	if (check_solution(s))
	{
		free_all(NULL, NULL, s);
		exit(0);
	}
}
