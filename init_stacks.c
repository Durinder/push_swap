/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:53:07 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 17:19:27 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft/libft.h"
#include <limits.h>

void	init_b(t_stacks *stacks)
{
	int	*stack;

	stack = ft_memalloc(sizeof(int *) * stacks->elems);
	if (stack == NULL)
		ft_error_exit("Failed to malloc for (int *)stack");
	stacks->b = stack;
	stacks->a_size = stacks->elems;
	stacks->b_size = 0;
}

int	count(char **input, char n)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (n == 1)
			ft_strdel(&input[i]);
		i++;
	}
	if (n == 1)
		free(input);
	return (i);
}

void	check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	if (size == 1)
		return ;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				ft_error_exit("Error: Duplicate number(s) in input.");
			}
			j++;
		}
		i++;
	}
}

int	*init(int argc, char **input)
{
	int	*stack;
	int	i;
	int	j;

	stack = ft_memalloc(sizeof(int *) * argc - 1);
	if (stack == NULL)
		ft_error_exit("Failed to malloc for (int *)stack");
	i = -1;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (j == 0 && input[i][j] == '-')
				j++;
			if (ft_isdigit(input[i][j]) == 0)
				ft_error_exit("Error: Invalid character in input.");
		}
		if (ft_atoi_l(input[i]) > INT_MAX || ft_atoi_l(input[i]) < INT_MIN)
			ft_error_exit("Error: A number too large or too small in input.");
		if (ft_strcmp(input[i], "") == 0)
			ft_error_exit("Error: Empty argument.");
		stack[i] = ft_atoi(input[i]);
	}
	return (stack);
}
