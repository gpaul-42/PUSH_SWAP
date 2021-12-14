/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 15:31:50 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_valid_param(int argc, char **argv, t_info *tab)
{
	int	i;
	int	n;

	i = 1;
	while (i < argc)
	{
		n = 0;
		while (argv[i][n])
		{
			if (ft_isdigit(argv[i][n]) == 0)
				error_free(tab, -1);
			n++;
		}
		i++;
	}
	return (1);
}

int	check_dup_param(t_info *tab)
{
	int	i;
	int	n;

	i = 0;
	while (i < tab->size_a)
	{
		n = i + 1;
		while (n < tab->size_a)
		{
			if (tab->a[n] == tab->a[i])
				error_free(tab, 0);
			n++;
		}
		i++;
	}
	return (0);
}

int	cpy_arg(int argc, char **argv, t_info *tab)
{
	int				i;
	int				n;
	long long int	tmp;

	tab->size_a = argc - 1;
	tab->size_b = 0;
	check_valid_param(argc, argv, tab);
	tab->a = check_malloc(tab->size_a, tab, -1);
	i = 1;
	n = 0;
	while (i < argc)
	{
		tmp = ft_atoi(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_free(tab, 0);
		tab->a[n] = (int)tmp;
		n++;
		i++;
	}
	check_dup_param(tab);
	return (0);
}
