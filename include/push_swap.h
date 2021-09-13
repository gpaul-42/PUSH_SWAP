/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaul <gpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:04:40 by gpaul             #+#    #+#             */
/*   Updated: 2021/09/13 17:36:27 by gpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

#include <stdio.h>


typedef struct s_info
{
	int		size;
	int		*a;
	int		*b;
}				t_info;


/*
	ERROR
*/
void	ft_error(void);
void	error_free(t_info *tab);

/*
	PARSE
*/
int	*cpy_arg(int argc, char **argv, t_info *tab);

#endif
