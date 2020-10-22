/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhallama <jhallama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:33:31 by jhallama          #+#    #+#             */
/*   Updated: 2020/10/19 20:23:01 by jhallama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "checker.h"

void	solver(t_stacks *s);
void	solver_small(t_stacks *s);
void	solver_medium(t_stacks *s);
void	redirect(void (*f)(t_stacks *), t_stacks *s, char *cmd);
void	visualize(t_stacks *stacks);
#endif
