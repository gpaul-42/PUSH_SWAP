/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/24 02:59:34 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_info	*tab;

	if (argc < 2)
		ft_error();
	tab = malloc(sizeof(t_info));
	if (tab == NULL)
		ft_error();
	cpy_arg(argc, argv, tab);
	
	//printf("%d\n%d\n%d\n", tab->a[0],tab->a[1],tab->a[2]);
	solver(tab);
	//printf("%d\n%d\n%d\n", tab->a[0],tab->a[1],tab->a[2]);
	exit_free(tab);
	return (0);
}
