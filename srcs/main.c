/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/10/13 18:57:52 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_info	*tab;

	if (argc < 2)
		ft_error();
	tab = malloc(sizeof(t_info));
	if (tab == NULL)
		ft_error();
	if (argc == 2)
		cpy_arg2(argv, tab);
	else if (argc > 2)
		cpy_arg(argc, argv, tab);
	cpy_sort(tab);
	bubblesort(tab->sort, tab->size_sort);
	solver(tab);
	printArray(tab->a, tab->size_a);
	exit_free(tab);
	return (0);
}
