/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 19:05:17 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stdio.h>

typedef struct s_rad
{
	int		max_size;
	int		size;
	int		bit_len;
	int		n;
	int		i;
	int		first;

}				t_rad;

typedef struct s_info
{
	int		size_a;
	int		size_b;
	int		size_sort;
	int		size_simple;
	int		size_simple_b;
	int		*a;
	int		*b;
	int		*sort;
	int		*simple;
	int		*simple_b;
	int		x_push;
	t_rad	*rad;
}				t_info;

typedef struct s_five
{
	int		move1;
	int		move2;
}				t_five;

/*
	ERROR
*/
void	ft_error(void);
void	error_free(t_info *tab, int option);
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
int		rotate(int *tab, int size, t_info *struc, int option);
int		rev_rotate(int *tab, int size, t_info *struc, int option);
int		push(t_info *tab, int mode, int option);
/*
	UTILS
*/
void	*check_malloc(int size, t_info *tab, int option);
void	exit_free(t_info *tab, int option);
void	bubblesort(int arr[], int n);
/*
	SOLVING
*/
int		ft_is_sort(int *tab, int length);
int		solver(t_info *tab);
int		solve_5(t_info *tab, int loop);
int		solve_3(int *tab, int size, t_info *struc);
void	simplified(t_info *tab, int option);

#endif
