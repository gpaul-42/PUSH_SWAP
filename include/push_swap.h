/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/22 23:09:07 by gpaul            ###   ########.fr       */
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
	int		size_simple;
	int		size_simple_b;
	int		*a;
	int		*b;
	int		*sort;
	int		*simple;
	int		*simple_b;
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
void	simplified(t_info *tab);

int		rra_or_ra(t_info *tab);
void	rra_ra(t_info *tab, int mode);

/*
	CONVERT BASE
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		ft_atoi_base(char *str, char *base_from, char *base_to);
int		check_base(char *base);


/*
	SOLVING
*/
int	ft_is_sort(int *tab, int length);
int	solver(t_info *tab);

#endif
