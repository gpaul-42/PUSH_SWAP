/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:36:06 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/29 18:33:29 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	rra_or_ra2(t_info *tab)
{
	int	i;
	int	n;

	i = 0;
	while (tab->b[0] > tab->a[0] && i != tab->size_a)
	{
		rotate(tab->a, tab->size_a);
		i++;
	}
	n = i;
	while (i > 0 && i != tab->size_a)
	{
		rev_rotate(tab->a, tab->size_a);
		i--;
	}
	return (n);
}

int	rra_or_ra(t_info *tab)
{
	int	i;
	int	n;
	int	x;

	i = 0;
	n = rra_or_ra2(tab);
	while (tab->b[0] > tab->a[0] && i != tab->size_a)
	{
		rev_rotate(tab->a, tab->size_a);
		i++;
	}
	x = i;
	while (i > 0 && i != tab->size_a)
	{
		rotate(tab->a, tab->size_a);
		i--;
	}
	if (n < x)
		return (0);
	return (1);
}

void	rra_ra2(t_info *tab)
{
	int	i;

	i = 0;
	while (tab->b[0] > tab->a[0] && i != tab->size_a)
	{
		rev_rotate(tab->a, tab->size_a);
		write(1, "rra\n", 4);
		i++;
	}
	push(tab, 1);
	while (i + 1 > 0 && i != tab->size_a)
	{
		rotate(tab->a, tab->size_a);
		write(1, "ra\n", 3);
		i--;
	}
}

void	rra_ra(t_info *tab, int mode)
{
	int	i;

	i = 0;
	if (mode == 1)
		rra_ra2(tab);
	else
	{
		while (tab->b[0] > tab->a[0] && i != tab->size_a)
		{
			rotate(tab->a, tab->size_a);
			write(1, "ra\n", 3);
			i++;
		}
		push(tab, 1);
		while (i + 1 > 0 && i != tab->size_a)
		{
			rev_rotate(tab->a, tab->size_a);
			write(1, "rra\n", 4);
			i--;
		}
	}
}
