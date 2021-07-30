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

static int	*init_b(t_stacks *stacks)
{
	int	*stack;

	stack = ft_memalloc(sizeof(int *) * stacks->elems);
	if (stack == NULL)
		ft_error_exit("Failed to malloc for (int *)stack");
	stacks->b = stack;
	stacks->b_size = 0;
	return (stack);
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

int	*init(int argc, char **input)
{
	int	*stack;
	int	i;
	int	j;

	stack = ft_memalloc(sizeof(int *) * argc - 1);
	if (stack == NULL)
		ft_error_exit("Error");
	i = -1;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (j == 0 && input[i][j] == '-')
				j++;
			if (ft_isdigit(input[i][j]) == 0)
				ft_error_exit("Error");
		}
		if (ft_atoi_l(input[i]) > INT_MAX || ft_atoi_l(input[i]) < INT_MIN)
			ft_error_exit("Error");
		if (ft_strcmp(input[i], "") == 0)
			ft_error_exit("Error");
		stack[i] = ft_atoi(input[i]);
	}
	return (stack);
}

t_stacks	*init_stacks(char **input, int argc, char **argv)
{
	t_stacks	*stacks;
	
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error_exit("Error");
	if (input)
	{
		stacks->v = v_check(&input, 1);
		stacks->a = init(count(input, 0), input);
		stacks->elems = count(input, 1);
	}
	else
	{
		stacks->v = v_check(&argv, 0);
		stacks->a = init(argc, ++argv);
		stacks->elems = (argc - 1 - stacks->v);
	}
	stacks->buffer = NULL;
	stacks->b = init_b(stacks);
	stacks->a_size = stacks->elems;
	check_duplicates(stacks->a, stacks->elems);
	return (stacks);
}
