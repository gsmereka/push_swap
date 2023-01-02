/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_is_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:53:10 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 14:00:18 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static int	stack_a_is_sorted(t_data *data);

void	check_if_is_sorted(t_data *data)
{
	if (stack_a_is_sorted(data))
		ft_printf("OK\n");
	if (!stack_a_is_sorted(data))
		ft_printf("KO\n");
}

static int	stack_a_is_sorted(t_data *data)
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
