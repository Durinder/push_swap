/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:45:08 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 17:36:37 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	*init_stacks(char **input, int argc, char **argv)
{
	t_stacks	*stacks;
//	t_buffer	*buffer;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error_exit("Error: Failed to malloc (t_stacks *)stacks");
	stacks->v = 0;
	if (input)
	{
		stacks->a = init(count(input, 0), input);
		stacks->elems = count(input, 1);
	}
	else
	{
		stacks->a = init(argc, ++argv);
		stacks->elems = (argc - 1 - stacks->v);
	}
	check_duplicates(stacks->a, stacks->elems);
	stacks->buffer = NULL;
	init_b(stacks);
//	buffer = ft_memalloc(sizeof(t_buffer));
//	if (buffer == NULL)
//		ft_error_exit("Error: Failed to malloc.");
//	stacks->buffer->cmd = NULL;
//	stacks->buffer->next = NULL;
//	stacks->buffer = buffer;
	return (stacks);
}

int	main(int argc, char **argv)
{
	char		**input;
	t_stacks	*stacks;

	input = NULL;
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		if (input[0] == NULL)
			ft_error_exit("Error: Empty argument.");
	}
	stacks = init_stacks(input, argc, argv);
	solver(stacks);
	free_all(NULL, NULL, stacks);
	return (0);
}
