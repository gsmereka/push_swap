/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/08 22:56:25 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	radix_sort_split(int digit_value, t_data *data);
static void	radix_sort_merge(t_data *data);
static int	ft_quick_sort(int init, int pivot, t_data *data);
static int	reajust_nodes(int init, int pivot, t_data *data);

void	sort_big_list(t_data *data)
{
	int	init;
	int	pivot;

	init = 0;
	test_program(data);
	finalize(data);
	pivot = data->stack_a_size - 1;
	ft_quick_sort(init, pivot, data);
}

static int	ft_quick_sort(int init, int pivot, t_data *data)
{
	int	new_pivot;

	if (init > pivot)
		return (0);
	new_pivot = reajust_nodes(init, pivot, data);
	ft_quick_sort(init, new_pivot - 1, data);
	ft_quick_sort(new_pivot + 1, pivot, data);
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
	while (i < init)
	{
		rotates_init++;
		ft_rotate('a', data);
		i++;
	}
	while (i < pivot)
	{
		i++;
		if (data->stack_a->simplified_nmb < pivot_node->simplified_nmb)
		{
			data->stack_a_size--;
			data->stack_b_size++;
			ft_push('b', data);
		}
		else
		{
			rotates++;
			ft_rotate('a', data);
		}
	}
	new_pivot = data->stack_b_size - 1;
	while (rotates)
	{
		rotates--;
		ft_reverse_rotate('a', data);
	}
	while (data->stack_b)
	{
		ft_push('a', data);
		data->stack_a_size++;
		data->stack_b_size--;
	}
	while (rotates_init)
	{
		rotates_init--;
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
