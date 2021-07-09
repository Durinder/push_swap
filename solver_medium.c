/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_medium.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:21:35 by jhallama          #+#    #+#             */
/*   Updated: 2021/07/07 18:26:01 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stacks *s, int co)
{
	while (s->a_size > 3)
	{
		ft_putnbr(s->a_size);
		while (s->a[0] > co && s->a_size > 3)
		{
//			ft_printf("push");
			redirect_buf(s, s->b, "push");
		}
		if (s->a[1] > co)
		{
//			ft_printf("rotate");
			if (s->b[0] > s->b[1])
				redirect_buf(s, NULL, "rr");
			else
				redirect_buf(s, s->a, "rotate");
		}
		else
		{
//			ft_printf("reverse_rotate");
			if (s->b[1] > s->b[0])
				redirect_buf(s, NULL, "rrr");
			else
				redirect_buf(s, s->a, "rrotate");
		}
	}
}

static void	sort_array(int **array, size_t elems)
{
	int		tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < elems - 1)
	{
		j = i + 1;
		while (j < elems)
		{
			if (array[0][i] > array[0][j])
			{
				tmp = array[0][i];
				array[0][i] = array[0][j];
				array[0][j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	get_cut_off(t_stacks *s)
{
	int	*sorted;
	int	i;
	int	cut_off;

	sorted = ft_memalloc(sizeof(int *) * s->elems - 1);
	if (sorted == NULL)
		free_all("Error: Failed to malloc", NULL, s);
	i = 0;
	while (i < s->elems)
	{
		sorted[i] = s->a[i];
		i++;
	}
	sort_array(&sorted, s->elems);
	cut_off = sorted[2];
	free(sorted);
	return (cut_off);
}

void	solver_medium(t_stacks *s)
{
	int		cut_off;

	cut_off = get_cut_off(s);
	ft_putnbr(cut_off);
	ft_printf("apua");
	push_to_b(s, cut_off); // FIX
	ft_printf("testi");
	solver_small_dual(s);
}
