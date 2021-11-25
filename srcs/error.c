/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:11:02 by gpaul             #+#    #+#             */
/*   Updated: 2021/11/25 15:59:00 by gpaul            ###   ########.fr       */
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
	if (tab->simple != NULL)
		free(tab->simple);
	if (tab->sort != NULL)
		free(tab->sort);
	if (tab->rad != NULL)
		free(tab->rad);
	free(tab);
	ft_error();
}

void	exit_free(t_info *tab)
{
	if (tab->a != NULL)
		free(tab->a);
	if (tab->simple != NULL)
		free(tab->simple);
	if (tab->sort != NULL)
		free(tab->sort);
	if (tab->rad != NULL)
		free(tab->rad);
	free(tab);
	exit(EXIT_SUCCESS);
}
