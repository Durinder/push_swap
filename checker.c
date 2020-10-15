/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:45:08 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/15 17:45:10 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
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
			free_all("Error: Empty argument.", input, NULL);
	}
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		free_all("Error: Failed to malloc (t_stacks *)stacks", input, stacks);
	stacks->v = (input) ? v_check(&input, 1) : v_check(&argv, 0);
	stacks->a = (input) ? init(count(input, 0), input) : init(argc, ++argv);
	stacks->elems = (input) ? count(input, 1) : (size_t)argc - 1 - stacks->v;
	check_duplicates(stacks->a, stacks->elems);
	init_b(stacks);
	read_commands(stacks);
	check_solution(stacks) == 1 ? ft_printf("OK") : ft_printf("KO");
	free_all(NULL, NULL, stacks);
	return (0);
}
