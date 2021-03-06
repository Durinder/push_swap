/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:35:16 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 18:23:35 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redirect_buf(t_stacks *s, int *p, const char *cmd)
{
	if (p == s->a)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			add_to_last(s, "sa");
		if (ft_strcmp(cmd, "push") == 0)
			add_to_last(s, "pa");
		if (ft_strcmp(cmd, "rotate") == 0)
			add_to_last(s, "ra");
		if (ft_strcmp(cmd, "rrotate") == 0)
			add_to_last(s, "rra");
	}
	else if (p == s->b)
	{
		if (ft_strcmp(cmd, "switch") == 0)
			add_to_last(s, "sb");
		if (ft_strcmp(cmd, "push") == 0)
			add_to_last(s, "pb");
		if (ft_strcmp(cmd, "rotate") == 0)
			add_to_last(s, "rb");
		if (ft_strcmp(cmd, "rrotate") == 0)
			add_to_last(s, "rrb");
	}
	else if (p == NULL)
	{
		add_to_last(s, cmd);
	}
//	ft_printf("%s\n", cmd);
}

static void	*get_pointer(const char *cmd)
{
	if (ft_strcmp(cmd, "sa") == 0)
		return (sa);
	else if (ft_strcmp(cmd, "sb") == 0)
		return (sb);
	else if (ft_strcmp(cmd, "ss") == 0)
		return (ss);
	else if (ft_strcmp(cmd, "pa") == 0)
		return (pa);
	else if (ft_strcmp(cmd, "pb") == 0)
		return (pb);
	else if (ft_strcmp(cmd, "ra") == 0)
		return (ra);
	else if (ft_strcmp(cmd, "rb") == 0)
		return (rb);
	else if (ft_strcmp(cmd, "rr") == 0)
		return (rr);
	else if (ft_strcmp(cmd, "rra") == 0)
		return (rra);
	else if (ft_strcmp(cmd, "rrb") == 0)
		return (rrb);
	else if (ft_strcmp(cmd, "rrr") == 0)
		return (rrr);
	ft_error_exit("Error: invalid command.");
	exit(0);
}

/*static void	init_operation_pointers()
{
	g_operations[0] = sa;
	g_operations[1] = sb;
	g_operations[2] = ss;
	g_operations[3] = pa;
	g_operations[4] = pb;
	g_operations[5] = ra;
	g_operations[6] = rb;
	g_operations[7] = rr;
	g_operations[8] = rra;
	g_operations[9] = rrb;
	g_operations[10] = rrr;
}*/

void	redirect(void (*f)(t_stacks *), t_stacks *s, const char *cmd, int print)
{
//	void	(*g_operations[11])(t_stacks *stacks) = {
//sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
	
	if (print)
		ft_printf("%s\n", cmd);
	if (f != NULL)
		f(s);
	else
		redirect(get_pointer(cmd), s, cmd, print);
//	if (check_solution(s))
//	{
//		ft_printf("solved!\n");
//		exit(0);
//	}
}
