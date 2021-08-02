/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:45:08 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 16:30:58 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			ft_error_exit("Error");
	}
	stacks = init_stacks(input, argc, argv);
	solver(stacks);
	free_stacks(stacks);
	return (0);
}
