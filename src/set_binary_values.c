/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_binary_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:36:06 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/28 21:42:28 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static char	*int_to_binary_char(int nmb);

void	set_binary_values(t_list *stack)
{
	while (stack->next)
	{
		stack->binary_nmb = int_to_binary_char(stack->nmb);
		stack = stack->next;
	}
}

static char	*int_to_binary_char(int nmb)
{
	return (NULL);
}
