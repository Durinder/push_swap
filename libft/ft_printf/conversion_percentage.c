/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_percentage.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:14:08 by jhallama          #+#    #+#             */
/*   Updated: 2020/01/29 12:55:55 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_fields *fields)
{
	fields->min--;
	write(1, "%", 1);
	fields->result++;
}

static void	zeroes_and_spaces(t_fields *fields)
{
	if (fields->zero == 1 && fields->minus == 0)
	{
		while (fields->min > 1)
		{
			fields->min--;
			write(1, "0", 1);
			fields->result++;
		}
	}
	while (fields->minus == 0 && fields->min > 1)
	{
		fields->min--;
		write(1, " ", 1);
		fields->result++;
	}
}

void		conversion_percentage(t_fields *fields)
{
	zeroes_and_spaces(fields);
	print(fields);
	if (fields->minus == 1 && fields->zero == 0)
	{
		while (fields->min-- > 0)
		{
			write(1, " ", 1);
			fields->result++;
		}
	}
}
