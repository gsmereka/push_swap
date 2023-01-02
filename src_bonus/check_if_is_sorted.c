/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:53:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 13:54:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	stack_a_is_sorted(t_data *data)
{
	t_list	*node;

	if (!data->stack_a)
		return (0);
	if (data->stack_b)
		return (0);
	node = data->stack_a;
	while (node->next)
	{
		if (node->nmb > node->next->nmb)
			return (0);
		node = node->next;
	}
	return (1);
}
