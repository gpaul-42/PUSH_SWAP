/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplified.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:15:21 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/22 23:06:58 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simplified(t_info *tab)
{
	int	i;
	int	x;
	int	j;

	tab->simple = check_malloc(tab->size_a, tab);
	tab->size_simple = tab->size_a;
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
}
