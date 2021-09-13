/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/13 19:56:18 by gpaul            ###   ########.fr       */
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

static int	push_utils(int *from, int size)
{
	int	*tmp;
	int	i;
	int	n;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (1);
	n = 0;
	i = 1;
	while (i < size)
	{
		tmp[n] = from[i];
		i++;
		n++;
	}
	n = 0;
	while (n < size)
	{
		from[n] = tmp[n];
		n++;
	}
	free(tmp);
	return (0);
}

int	push(int *from, int *to, int size)
{
	int	*tmp;
	int	i;
	int	n;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (1);
	i = 0;
	n = 1;
	while (i < size)
	{
		tmp[n] = to[i];
		i++;
		n++;
	}
	tmp[0] = from[0];
	n = 0;
	while (n < size)
	{
		to[n] = tmp[n];
		n++;
	}
	push_utils(from, size);
	free(tmp);
	return (0);
}

int	rotate(int *tab, int size)
{
	int	*tmp;
	int	i;
	int	x;

	i = 0;
	x = 1;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (1);
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

int	rev_rotate(int *tab, int size)
{
	int	*tmp;
	int	i;
	int	x;

	i = 1;
	x = 0;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return (1);
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
