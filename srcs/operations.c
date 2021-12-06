/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/29 16:26:34 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(int *tab)
{
	int	tmp;

	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	return (0);
}

int	rotate(int *tab, int size, t_info *struc, int option)
{
	int	*tmp;
	int	i;
	int	x;

	i = 0;
	x = 1;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		error_free(struc, option);
	while (x < size)
	{
		tmp[i] = tab[x];
		i++;
		x++;
	}
	tmp[i] = tab[0];
	x = 0;
	while (x < size)
	{
		tab[x] = tmp[x];
		x++;
	}
	free(tmp);
	return (0);
}

int	rev_rotate(int *tab, int size, t_info *struc, int option)
{
	int	*tmp;
	int	i;
	int	x;

	i = 1;
	x = 0;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		error_free(struc, option);
	tmp[0] = tab[size - 1];
	while (x < size - 1)
	{
		tmp[i] = tab[x];
		i++;
		x++;
	}
	x = 0;
	while (x < size)
	{
		tab[x] = tmp[x];
		x++;
	}
	free(tmp);
	return (0);
}
