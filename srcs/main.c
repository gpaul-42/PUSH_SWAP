/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/22 23:34:39 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void radix(t_info *tab)
{
	int size = tab->size_simple;
	int max_num = size - 1;
	int max_bits = 0;

	while ((max_num >> max_bits) != 0)
		++max_bits;

	for (int i = 0; i < max_bits; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			int num = tab->simple[0];
			if (((num >> i)&1) == 1)
			{
				rotate(tab->simple, tab->size_simple);
				rotate(tab->a, tab->size_a);
				write(1, "ra\n", 3);
			}
			else
				push(tab, 0);
		}
		while (tab->size_simple_b)
			push(tab, 1);
	}
}

int main(int argc, char **argv)
{
	t_info *tab;

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
	//printArray(tab->a, tab->size_a);
	printf("%d\n", tab->a[0]);

	//simplified(tab);
	//radix(tab);
	exit_free(tab);
	return (0);
}
