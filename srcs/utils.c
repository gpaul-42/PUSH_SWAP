/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:04:01 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/14 18:26:30 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*check_malloc(int size, t_info *tab, int option)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		error_free(tab, option);
	return (tmp);
}
