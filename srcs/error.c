/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/10/06 17:21:00 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}

void	error_free(t_info *tab)
{
	if (tab->a != NULL)
		free(tab->a);
	if (tab->b != NULL)
		free(tab->b);
	free(tab);
	ft_error();
}

void	exit_free(t_info *tab)
{
	if (tab->a != NULL)
		free(tab->a);
	if (tab->b != NULL)
		free(tab->b);
	if (tab->sort != NULL)
		free(tab->sort);
	free(tab);
	exit(EXIT_SUCCESS);
}
