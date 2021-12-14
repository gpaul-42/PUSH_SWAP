/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/12/14 18:21:57 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	error_free(t_info *tab, int option)
{
	if (option >= 0)
		free(tab->a);
	if (option >= 1)
		free(tab->sort);
	if (option >= 2)
		free(tab->rad);
	if (option >= 3)
		free(tab->simple);
	free(tab);
	ft_error();
}

void	exit_free(t_info *tab, int option)
{
	if (option > 0)
		free(tab->a);
	if (option >= 1)
		free(tab->sort);
	if (option >= 2)
		free(tab->rad);
	if (option >= 3)
		free(tab->simple);
	free(tab);
	exit(EXIT_SUCCESS);
}
