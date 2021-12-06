/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 01:18:15 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/06 18:30:10 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve_33(int *tab, int size, t_info *struc)
{
	swap(tab);
	write(1, "sa\n", 3);
	rev_rotate(tab, size, struc, 1);
	write(1, "rra\n", 4);
}

static int	solve_3(int *tab, int size, t_info *struc)
{
	if (ft_is_sort(tab, size) == 1)
		return (0);
	if (tab[0] > tab[1] && tab[0] > tab[2] && tab[1] > tab[2])
		solve_33(tab, size, struc);
	else if (tab[2] > tab[1] && tab[2] > tab[0] && tab[0] > tab[1])
	{
		swap(tab);
		write(1, "sa\n", 3);
		solve_3(tab, size, struc);
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && (tab[0] > tab[2]
			|| tab[0] < tab[2]))
	{
		rev_rotate(tab, size, struc, 1);
		write(1, "rra\n", 4);
		solve_3(tab, size, struc);
	}
	else if (tab[0] > tab[1] && tab[0] > tab[2] && (tab[1] < tab[2]
			|| tab[1] > tab[2]))
	{
		rotate(tab, size, struc, 1);
		write(1, "ra\n", 4);
		solve_3(tab, size, struc);
	}
	return (0);
}

int	solver(t_info *tab)
{
	if (ft_is_sort(tab->a, tab->size_a) == 1)
		return (0);
	if (tab->size_a == 2 && ft_is_sort(tab->a, tab->size_a) != 1)
	{
		swap(tab->a);
		write(1, "sa\n", 3);
		exit_free(tab, 1);
	}
	if (tab->size_a == 3)
	{
		solve_3(tab->a, tab->size_a, tab);
		exit_free(tab, 1);
	}
	else
	{
		tab->rad = malloc(sizeof(t_rad) * 1);
		if (tab->rad == NULL)
			error_free(tab, 1);
		simplified(tab, tab->rad);
	}
	return (0);
}
