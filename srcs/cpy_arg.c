/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/14 18:22:29 by gpaul            ###   ########.fr       */
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
				error_free(tab);
			n++;
		}
		i++;
	}
	return (1);
}

static int	check_dup_param(t_info *tab)
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
				error_free(tab);
			n++;
		}
		i++;
	}
	return (0);
}

int	*cpy_arg(int argc, char **argv, t_info *tab)
{
	int	i;
	int	n;

	tab->size_a = argc - 1;
	tab->size_b = 0;
	check_valid_param(argc, argv, tab);
	tab->a = check_malloc(tab->size_a, tab);
	i = 1;
	n = 0;
	while (i < argc)
	{
		tab->a[n] = ft_atoi(argv[i]);
		n++;
		i++;
	}
	check_dup_param(tab);
	return (0);
}
