/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:45:08 by jhallama          #+#    #+#             */
/*   Updated: 2021/08/02 15:20:37 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	read_commands(stacks);
	if (check_solution(stacks) == 1)
		ft_putendl_fd("OK", 0);
	else
		ft_putendl_fd("KO", 2);
	free_stacks(stacks);
	return (0);
}
