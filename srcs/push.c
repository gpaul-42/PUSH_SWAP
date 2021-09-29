/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/24 01:22:47 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*push_fr(int size_fr, int *fr, t_info *tab)
{
	int	*tmp_fr;
	int	n;
	int	i;

	n = 0;
	i = 1;
	tmp_fr = check_malloc(size_fr - 1, tab);
	while (i < size_fr)
	{
		tmp_fr[n] = fr[i];
		n++;
		i++;
	}
	tab->x_push = fr[0];
	free(fr);
	fr = check_malloc(size_fr - 1, tab);
	i = 0;
	while (i < size_fr - 1)
	{
		fr[i] = tmp_fr[i];
		i++;
	}
	free(tmp_fr);
	return (fr);
}

static int	*push_to(int size_to, int *to, t_info *tab)
{
	int	*tmp_to;
	int	n;
	int	i;

	tmp_to = check_malloc(size_to + 1, tab);
	i = 1;
	n = 0;
	while (n < size_to)
	{
		tmp_to[i] = to[n];
		n++;
		i++;
	}
	tmp_to[0] = tab->x_push;
	if (size_to > 0)
		free(to);
	to = check_malloc(size_to + 1, tab);
	i = 0;
	while (i < size_to + 1)
	{
		to[i] = tmp_to[i];
		i++;
	}
	free(tmp_to);
	return (to);
}

static int	push_a_b(t_info *tab)
{
	tab->a = push_fr(tab->size_a, tab->a, tab);
	tab->b = push_to(tab->size_b, tab->b, tab);
	tab->size_a = tab->size_a - 1;
	tab->size_b = tab->size_b + 1;
	tab->x_push = 0;
	return (0);
}

static int	push_b_a(t_info *tab)
{
	tab->b = push_fr(tab->size_b, tab->b, tab);
	tab->a = push_to(tab->size_a, tab->a, tab);
	tab->size_a = tab->size_a + 1;
	tab->size_b = tab->size_b - 1;
	tab->x_push = 0;
	return (0);
}

int	push(t_info *tab, int mode)
{
	if (mode == 0)
	{
		push_a_b(tab);
		write(1, "pb\n", 1);
	}
	else
	{
		push_b_a(tab);
		write(1, "pa\n", 1);
	}
	return (0);
}
