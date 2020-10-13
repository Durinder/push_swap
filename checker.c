/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:04:56 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:34 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	char		**input;
	t_stacks	*stacks;

	input = NULL;
	if (!(stacks = (t_stacks *)malloc(sizeof(t_stacks))))
		ft_error_exit("Error: Failed to malloc for (t_stacks *)stacks");
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		if (input[0] == NULL)
			ft_error_exit("Error: Empty argument.");
	}
	stacks->v = (input == NULL) ? v_check(&argv, 0) : v_check(&input, 1);
	stacks->a = (input == NULL) ? init(argc, ++argv) : init(count_elems(input, 0), input);
	stacks->elems = (input) ? count_elems(input, 1) : (size_t)argc - 1 - stacks->v;
	check_duplicates(stacks->a, stacks->elems);
	init_b(stacks);
	read_commands(stacks);
	check_solution(stacks) == 1 ? ft_printf("OK") : ft_printf("KO");
	free(stacks->a);
	free(stacks->b);
	free(stacks);
	return (0);
}
