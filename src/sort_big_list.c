/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 16:35:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	max_binary_size(t_data *data);

int	sort_big_list(t_data *data)
{
	int	max_size;
	int	digit_pos;
	int	less_value_digit_pos;
	int	i;

	digit_pos = 1;
	max_size = max_binary_size(data);
	while (digit_pos < max_size)
	{
		i = 0;
		while (i < data->max_stack_size)
		{
			less_value_digit_pos = ft_strlen(data->stack_a->binary_nmb);
			less_value_digit_pos = less_value_digit_pos - digit_pos;
			if (less_value_digit_pos < 0)
				ft_push('a', data);
			else if (data->stack_a->binary_nmb[less_value_digit_pos] == '0')
				ft_push('a', data);
			else
				ft_rotate('a', data);
			i++;
		}
		while (data->stack_b)
			ft_push('b', data);
		digit_pos++;
	}
	return (0);
}

static int	max_binary_size(t_data *data)
{
	t_list	*big_node;
	t_list	*node;
	int		max_size;

	big_node = data->stack_a;
	node = data->stack_a;
	while (node)
	{
		if (node->simplified_nmb > big_node->simplified_nmb)
			big_node = node;
		node = node->next;
	}
	max_size = ft_strlen(big_node->binary_nmb);
	return (max_size);
}
