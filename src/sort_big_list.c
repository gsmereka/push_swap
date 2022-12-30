/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 17:38:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	max_binary_size(t_data *data);
static void	split_nodes_by_digit_value(int digit_value, t_data *data);
static void	merge_stacks(t_data *data);

int	sort_big_list(t_data *data)
{
	int	digit_pos;
	int	max_size;

	digit_pos = 1;
	max_size = max_binary_size(data);
	while (digit_pos < max_size)
	{
		split_nodes_by_digit_value(digit_pos, data);
		merge_stacks(data);
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

static void	split_nodes_by_digit_value(int digit_pos, t_data *data)
{
	int	less_value_digit_pos;
	int	i;

	i = 0;
	while (i < data->max_stack_size)
	{
		less_value_digit_pos = ft_strlen(data->stack_a->binary_nmb);
		less_value_digit_pos = less_value_digit_pos - digit_pos;
		if (less_value_digit_pos < 0)
		{
			ft_push('a', data);
			ft_printf("pa\n");
		}
		else if (data->stack_a->binary_nmb[less_value_digit_pos] == '0')
		{
			ft_push('a', data);
			ft_printf("pa\n");
		}
		else
		{
			ft_rotate('a', data);
			ft_printf("ra\n");
		}
		i++;
	}
}

static void	merge_stacks(t_data *data)
{
	while (data->stack_b)
	{
		ft_push('b', data);
		ft_printf("pb\n");
	}
}
