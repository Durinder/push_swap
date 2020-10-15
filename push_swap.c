/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:33:01 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/25 11:33:18 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
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
	check_duplicates(stacks->a, stacks->elems);
	init_b(stacks);
	return (0);
}
