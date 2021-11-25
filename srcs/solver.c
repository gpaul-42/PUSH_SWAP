/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:18:15 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/25 15:59:41 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	solve_3(int *tab, int size)
{
	if (ft_is_sort(tab, size) == 1)
		return (0);
	if (tab[2] > tab[1] && tab[2] > tab[0] && tab[0] > tab[1])
	{
		swap(tab);
		write(1, "sa\n", 3);
		solve_3(tab, size);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && (tab[0] > tab[2]
			|| tab[0] < tab[2]))
	{
		rev_rotate(tab, size);
		write(1, "rra\n", 4);
		solve_3(tab, size);
	}
	else if (tab[0] > tab[1] && tab[0] > tab[2] && (tab[1] < tab[2]
			|| tab[1] > tab[2]))
	{
		rotate(tab, size);
		write(1, "ra\n", 4);
		solve_3(tab, size);
	}
	return (0);
}

int	solver(t_info *tab)
{
	if (tab->size_a == 2 && ft_is_sort(tab->a, tab->size_a) != 1)
	{
		swap(tab->a);
		write(1, "sa\n", 3);
	}
	if (tab->size_a == 3 && tab->size_b == 0)
		solve_3(tab->a, tab->size_a);
	else
	{
		tab->rad = malloc(sizeof(t_rad));
		if (tab->rad == NULL)
			error_free(tab);
		simplified(tab, tab->rad);
	}
	return (0);
}
