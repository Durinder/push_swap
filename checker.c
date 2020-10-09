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
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (argc == 1)
		exit(0);
	else if (argc == 2)
	{
		input = ft_strsplit(argv[1], ' ');
		if (input[0] == NULL)
			ft_error_exit("Error: Empty argument.");
	}
	stacks->v = (input == NULL) ? v_check(argv) : v_check(input);
	stacks->a = (input == NULL) ? init(argc, ++argv) : init(count_elems(input, 0), input);
	stacks->elems = (input) ? count_elems(input, 1) : 1;
	check_duplicates(stacks->a, stacks->elems);
	init_b(stacks);
	read_commands(stacks);
	check_solution(stacks) == 1 ? ft_printf("OK") : ft_printf("KO");
	free(stacks->a);
	free(stacks->b);
	free(stacks);
//	while (1) {};
	return (0);
}
