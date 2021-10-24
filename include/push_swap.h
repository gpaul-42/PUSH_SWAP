/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/10/13 17:30:02 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_info
{
	int		size_a;
	int		size_b;
	int		size_sort;
	int		*a;
	int		*b;
	int		*sort;
	int		x_push;
	int		chunk_nbr;
	int		chunk_rest;
}				t_info;


void printArray(int arr[], int size);



/*
	ERROR
*/
void	ft_error(void);
void	error_free(t_info *tab);
/*
	PARSE
*/
int		cpy_arg(int argc, char **argv, t_info *tab);
int		cpy_arg2(char **argv, t_info *tab);
int		check_dup_param(t_info *tab);
void	cpy_sort(t_info *tab);
/*
	OPERATIONS
*/
int		swap(int *tab);
int		rotate(int *tab, int size);
int		rev_rotate(int *tab, int size);
int		push(t_info *tab, int mode);
/*
	UTILS
*/
void	*check_malloc(int size, t_info *tab);
void	exit_free(t_info *tab);
void	bubblesort(int arr[], int n);
int		rra_or_ra(t_info *tab);


void	rra_ra(t_info *tab, int mode);


/*
	SOLVING
*/
int	ft_is_sort(int *tab, int length);
int	solver(t_info *tab);

#endif
