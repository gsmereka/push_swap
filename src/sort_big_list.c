/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/09 00:27:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	radix_sort_split(int digit_value, t_data *data);
static void	radix_sort_merge(t_data *data);
static int	ft_quick_sort(int init, int end, t_data *data);
static int	reajust_nodes(int init, int pivot, t_data *data);

void	sort_big_list(t_data *data)
{
	int	init;
	int	end;

	init = 0;
	// test_program(data);
	// finalize(data);
	end = data->stack_a_size - 1;
	ft_quick_sort(init, end, data);
}

static int	ft_quick_sort(int init, int end, t_data *data)
{
	int	pivot;

	if (init > end)
		return (0);
	pivot = reajust_nodes(init, end, data);
	ft_quick_sort(init, pivot - 1, data);
	ft_quick_sort(pivot + 1, end, data);
}

static int	add_rule_to_data(int rule, t_data *data)
{
	t_rule	*new_rule;
	t_rule	*last_node;

	new_rule = ft_calloc(1, sizeof(t_rule));
	if (!new_rule)
		return (-1);
	new_rule->instruction = rule;
	new_rule->next = NULL;
	last_node = data->rules;
	if (!last_node)
		data->rules = new_rule;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_rule;
	}
	return (0);
}

static int	reajust_nodes(int init, int pivot, t_data *data)
{
	t_list	*pivot_node;
	int		i;
	int		new_pivot;
	int		rotates;
	int		rotates_init;

	i = 0;
	rotates = 0;
	rotates_init = 0;
	pivot_node = ft_list_at(data->stack_a, pivot);
	while (rotates_init < init)
	{
		rotates_init++;
		ft_rotate('a', data);
		// add_rule_to_data(30, data);
	}
	while (init <= pivot)
	{
		init++;
		if (data->stack_a->simplified_nmb <= pivot_node->simplified_nmb)
		{
			ft_push('b', data);
			// add_rule_to_data(11, data);
		}
		else
		{
			rotates++;
			ft_rotate('a', data);
			// add_rule_to_data(30, data);
		}
	}
	new_pivot = pivot_node->simplified_nmb;
	while (rotates)
	{
		rotates--;
		ft_reverse_rotate('a', data);
		// add_rule_to_data(330, data);
	}
	while (data->stack_b)
	{
		ft_push('a', data);
		// add_rule_to_data(10, data);
	}
	while (rotates_init)
	{
		rotates_init--;
		// add_rule_to_data(330, data);
		ft_reverse_rotate('a', data);
	}
	return (new_pivot);
}

void	sort_big_list_3(t_data *data)
{
	int	digit_pos;

	digit_pos = 1;
	set_binary_values(data->stack_a, data);
	while (!stack_a_is_sorted(data))
	{
		radix_sort_split(digit_pos, data);
		radix_sort_merge(data);
		digit_pos++;
	}
}

static void	radix_sort_split(int digit_pos, t_data *data)
{
	int	less_value_digit_pos;
	int	i;

	i = 0;
	while (i < data->stack_a_size)
	{
		less_value_digit_pos = ft_strlen(data->stack_a->binary_nmb);
		less_value_digit_pos = less_value_digit_pos - digit_pos;
		if (less_value_digit_pos < 0
			|| data->stack_a->binary_nmb[less_value_digit_pos] == '0')
		{
			ft_push('b', data);
			data->stack_b_size++;
		}
		else
		{
			ft_rotate('a', data);
			print_necessary_pushes('a', data);
			ft_printf("ra\n");
		}
		i++;
	}
}

static void	radix_sort_merge(t_data *data)
{
	while (data->stack_b)
	{
		ft_push('a', data);
		if (!data->stack_b_size)
			print_necessary_pushes('b', data);
		else
			data->stack_b_size--;
	}
}
