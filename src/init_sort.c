/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:17:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 16:52:09 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	simplify_numbers(t_data *data);
static int	stack_is_sorted(t_data *data);

int	init_sort(t_data *data)
{
	if (stack_is_sorted(data))
		return (0);
	simplify_numbers(data);
	set_binary_values(data->stack_a, data);
	if (data->stack_a_size <= 3)
		sort_small_list(data);
	if (data->stack_a_size > 3 && data->stack_a_size <= 5)
		sort_average_list(data);
	if (data->stack_a_size > 5)
		sort_big_list(data);
	return (0);
}

static int	stack_is_sorted(t_data *data)
{
	t_list	*node;

	node = data->stack_a;
	while (node->next)
	{
		if (node->nmb > node->next->nmb)
			return (0);
		node = node->next;
	}
	return (1);
}

static void	simplify_numbers(t_data *data)
{
	t_list	*node;
	t_list	*another_node;
	int		value;

	node = data->stack_a;
	while (node)
	{
		value = 0;
		another_node = data->stack_a;
		while (another_node)
		{
			if (node->nmb > another_node->nmb)
				value++;
			another_node = another_node->next;
		}
		node->simplified_nmb = value;
		node = node->next;
	}
}
