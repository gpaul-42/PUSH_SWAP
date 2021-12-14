/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 17:44:11 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*push_fr(int size_fr, int *fr, t_info *tab, int option)
{
	int	*tmp_fr;
	int	n;
	int	i;

	n = 0;
	i = 1;
	tmp_fr = check_malloc(size_fr - 1, tab, option);
	while (i < size_fr)
	{
		tmp_fr[n] = fr[i];
		n++;
		i++;
	}
	tab->x_push = fr[0];
	if (size_fr > 0)
		free(fr);
	fr = check_malloc(size_fr - 1, tab, option);
	i = 0;
	while (i < size_fr - 1)
	{
		fr[i] = tmp_fr[i];
		i++;
	}
	free(tmp_fr);
	return (fr);
}

static int	*push_to(int size_to, int *to, t_info *tab, int option)
{
	int	*tmp_to;
	int	n;
	int	i;

	tmp_to = check_malloc(size_to + 1, tab, option);
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
	to = check_malloc(size_to + 1, tab, option);
	i = 0;
	while (i < size_to + 1)
	{
		to[i] = tmp_to[i];
		i++;
	}
	free(tmp_to);
	return (to);
}

static int	push_a_b(t_info *tab, int option)
{
	tab->a = push_fr(tab->size_a, tab->a, tab, option);
	tab->b = push_to(tab->size_b, tab->b, tab, option);
	tab->size_a = tab->size_a - 1;
	tab->size_b = tab->size_b + 1;
	tab->x_push = 0;
	tab->simple = push_fr(tab->size_simple, tab->simple, tab, option);
	tab->simple_b = push_to(tab->size_simple_b, tab->simple_b, tab, option);
	tab->size_simple--;
	tab->size_simple_b++;
	tab->x_push = 0;
	return (0);
}

static int	push_b_a(t_info *tab, int option)
{
	tab->b = push_fr(tab->size_b, tab->b, tab, option);
	tab->a = push_to(tab->size_a, tab->a, tab, option);
	tab->size_a = tab->size_a + 1;
	tab->size_b = tab->size_b - 1;
	tab->x_push = 0;
	tab->simple_b = push_fr(tab->size_simple_b, tab->simple_b, tab, option);
	tab->simple = push_to(tab->size_simple, tab->simple, tab, option);
	tab->size_simple++;
	tab->size_simple_b--;
	tab->x_push = 0;
	return (0);
}

int	push(t_info *tab, int mode, int option)
{
	if (mode == 0)
	{
		push_a_b(tab, option);
		write(1, "pb\n", 3);
	}
	else
	{
		push_b_a(tab, option);
		write(1, "pa\n", 3);
	}
	return (0);
}
