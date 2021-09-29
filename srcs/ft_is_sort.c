/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:52:42 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/24 02:02:41 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	cmp(int x, int y)
{
	if (x > y)
		return (-1);
	else
		return (0);
}

int	ft_is_sort(int *tab, int length)
{
	int	i;
	int	d;

	i = 1;
	d = 1;
	while (i < length)
	{
		if (cmp(tab[i - 1], tab[i]) < 0)
			d = 0;
		i++;
	}
	if (d == 1)
		return (1);
	else
		return (0);
}
