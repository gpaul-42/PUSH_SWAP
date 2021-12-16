/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve5_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:47:29 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/16 22:10:19 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	test_rev_rot(int *tab, int size, t_info *struc, int loop)
{
	int	i;
	int	move;

	i = 0;
	while (tab[0] != struc->sort[loop])
	{
		rev_rotate(tab, size, struc, 1);
		i++;
	}
	move = i;
	while (i > 0)
	{
		rotate(tab, size, struc, 1);
		i--;
	}
	return (move);
}

static int	test_rot(int *tab, int size, t_info *struc, int loop)
{
	int	i;
	int	move;

	i = 0;
	while (tab[0] != struc->sort[loop])
	{
		rotate(tab, size, struc, 1);
		i++;
	}
	move = i;
	while (i > 0)
	{
		rev_rotate(tab, size, struc, 1);
		i--;
	}
	return (move);
}

static int	solve_5_1(t_info *tab, int loop, t_five *count)
{
	count->move1 = test_rev_rot(tab->a, tab->size_a, tab, loop);
	count->move2 = test_rot(tab->a, tab->size_a, tab, loop);
	if (count->move1 > count->move2)
	{
		while (count->move2-- > 0)
		{
			rotate(tab->a, tab->size_a, tab, 1);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (count->move1-- > 0)
		{
			rev_rotate(tab->a, tab->size_a, tab, 1);
			write(1, "rra\n", 4);
		}
	}
	loop++;
	push(tab, 0, 3);
	if (loop < 2)
		solve_5_1(tab, loop, count);
	return (0);
}

int	solve_5(t_info *tab, int loop)
{
	t_five	*count;

	count = check_malloc(sizeof(t_five), tab, 3);
	solve_5_1(tab, loop, count);
	solve_3(tab->a, tab->size_a, tab);
	push(tab, 1, 3);
	push(tab, 1, 3);
	free(count);
	return (0);
}
