/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:04:56 by jhallama          #+#    #+#             */
/*   Updated: 2020/02/25 11:32:20 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*one_argument(char *input)
{
	size_t	i;
	int		*stack;

	i = 0;
	while (input[i++]);
	if (!(stack = ft_memalloc(i + 1)))
		return (NULL);
	return (stack);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
//	int	*stack_b;

	if (argc == 2)
	{
		stack_a = one_argument(argv[1]);
	}
	return (0);
}
