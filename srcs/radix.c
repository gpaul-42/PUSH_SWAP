/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:15:21 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/27 17:58:47 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	radix2(t_info *tab, t_rad *rad)
{
	rad->first = tab->simple[0];
	if (((rad->first >> rad->i) & 1) == 1)
	{
		rotate(tab->simple, tab->size_simple, tab, 3);
		rotate(tab->a, tab->size_a, tab, 3);
		write(1, "ra\n", 3);
	}
	else
		push(tab, 0, 3);
	rad->n++;
}

static void	radix(t_info *tab, t_rad *rad)
{
	rad->size = tab->size_simple;
	rad->max_size = rad->size - 1;
	rad->bit_len = 0;
	while ((rad->max_size >> rad->bit_len) != 0)
		++rad->bit_len;
	rad->i = 0;
	while (rad->i < rad->bit_len)
	{
		rad->n = 0;
		while (rad->n < rad->size)
			radix2(tab, rad);
		while (tab->size_simple_b)
			push(tab, 1, 3);
		rad->i++;
	}
}

void	simplified(t_info *tab, t_rad *rad)
{
	int	i;
	int	x;
	int	j;

	tab->simple = check_malloc(tab->size_a, tab, 2);
	tab->size_simple = tab->size_a;
	tab->size_simple_b = 0;
	i = 0;
	x = 0;
	while (i < tab->size_a)
	{
		j = 0;
		while (j < tab->size_a)
		{
			if (tab->a[i] == tab->sort[j])
			{
				tab->simple[x] = j;
				x++;
			}
			j++;
		}
		i++;
	}
	radix(tab, rad);
}
