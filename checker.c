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
	stacks->a = (input == NULL) ? init(argc, ++argv) : init(argc, input);
	stacks->elems = (input) ? count_elems(input) : (size_t)argc - 1;
	init_b(stacks);
	read_commands(stacks);
	check_solution(stacks) == 1 ? ft_printf("OK") : ft_printf("KO");
//	size_t i = 0;
//	while (i < stacks->elems)
//		ft_printf("%d\n", stacks->a[i++]);
//	free_stacks(stacks);
//	while (1) {};
	return (0);
}
