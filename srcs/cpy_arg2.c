/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_arg2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/10/13 20:02:38 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_valid_param2(char *argv, t_info *tab)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		while (ft_isdigit(argv[i]) == 1 && argv[i])
			i++;
		if (argv[i] == 32 || !argv[i])
			tab->size_a += 1;
		else
			error_free(tab, -1);
		if (argv[i])
			i++;
	}
	return (0);
}

static int	alloc(char *argv, t_info *tab)
{
	char	*tmp;
	int		i;
	int		n;
	int		x;

	x = 0;
	i = 0;
	tmp = malloc(sizeof(char) * 10);
	if (tmp == NULL)
		error_free(tab, 0);
	while (argv[i])
	{
		n = 0;
		while (ft_isdigit(argv[i]) == 1 && argv[i])
			tmp[n++] = argv[i++];
		if (argv[i])
			i++;
		tab->a[x] = ft_atoi(tmp);
		x++;
		ft_memset(tmp, '\0', 10);
	}
	free(tmp);
	return (0);
}

int	cpy_arg2(char **argv, t_info *tab)
{
	tab->size_b = 0;
	check_valid_param2(argv[1], tab);
	tab->a = check_malloc(tab->size_a, tab, -1);
	alloc(argv[1], tab);
	return (0);
}
