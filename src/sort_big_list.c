/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 15:27:55 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	max_binary_size(t_data *data);
static void	push_or_rotate_stack_a(int digit_value, t_data *data);
static void	push_entire_stack_b(t_data *data);
static void	print_stack_rules(int stack_rules, t_data *data);

int	sort_big_list(t_data *data)
{
	int	digit_pos;
	int	max_size;

	digit_pos = 1;
	max_size = max_binary_size(data);
	while (digit_pos < max_size)
	{
		push_or_rotate_stack_a(digit_pos, data);
		push_entire_stack_b(data);
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

static void	push_or_rotate_stack_a(int digit_pos, t_data *data)
{
	int	less_value_digit_pos;
	int	i;

	i = 0;
	data->pa_count = 0;
	while (i < data->max_stack_size)
	{
		less_value_digit_pos = ft_strlen(data->stack_a->binary_nmb);
		less_value_digit_pos = less_value_digit_pos - digit_pos;
		if (less_value_digit_pos < 0
			|| data->stack_a->binary_nmb[less_value_digit_pos] == '0')
		{
			ft_push('b', data);
			data->pa_count++;
		}
		else
		{
			ft_rotate('a', data);
			print_stack_rules('a', data);
		}
		i++;
	}
}

static void	push_entire_stack_b(t_data *data)
{
	while (data->stack_b)
	{
		ft_push('a', data);
		if (!data->pa_count)
			print_stack_rules('b', data);
		else
			data->pa_count--;
	}
}

static void	print_stack_rules(int stack_rules, t_data *data)
{
	if (stack_rules == 'a')
	{
		while (data->pa_count != 0)
		{
			ft_printf("pb\n");
			data->pa_count--;
		}
		ft_printf("ra\n");
	}
	if (stack_rules == 'b')
		ft_printf("pa\n");
}
