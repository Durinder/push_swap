/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:45:08 by jhallama          #+#    #+#             */
/*   Updated: 2021/06/29 17:09:29 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stacks	*init_stacks(char **input, int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (stacks == NULL)
		ft_error_exit("Error: Failed to malloc (t_stacks *)stacks");
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
		stacks->elems = (size_t)argc - 1 - stacks->v;
	}
	check_duplicates(stacks->a, stacks->elems);
	init_b(stacks);
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
	read_commands(stacks);
	if (check_solution(stacks) == 1)
		ft_printf("OK");
	else
		ft_printf("KO");
	free_all(NULL, NULL, stacks);
	return (0);
}
