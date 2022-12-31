/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:15:57 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 19:42:40 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_necessary_pushes(int rules, t_data *data)
{
	if (rules == 'a')
	{
		while (data->stack_b_size != 0)
		{
			ft_printf("pb\n");
			data->stack_b_size--;
		}
	}
	if (rules == 'b')
	{
		ft_printf("pa\n");
	}
}

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

int	stack_b_is_sorted(t_data *data)
{
	t_list	*node;

	if (data->stack_b == NULL)
		return (0);
	if (data->stack_a != NULL)
		return (0);
	node = data->stack_b;
	while (node->next)
	{
		if (node->nmb < node->next->nmb)
			return (0);
		node = node->next;
	}
	return (1);
}
