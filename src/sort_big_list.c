/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/09 15:59:06 by gsmereka         ###   ########.fr       */
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
	end = data->stack_a_size - 1;
	ft_quick_sort(init, end, data);
}

static int	ft_quick_sort(int init, int end, t_data *data)
{
	int	pivot;

	if (init > end)
		return (0);
	pivot = reajust_nodes(init, end, data);
	ft_quick_sort(pivot + 1, end, data);
	ft_quick_sort(init, pivot - 1, data);
	return (0);
}

static int	reajust_nodes(int pivot, int end, t_data *data)
{
	t_list	*pivot_node;
	int		new_pivot;
	int		rotates;
	int		rotates_end;

	rotates = 0;
	rotates_end = 0;
	pivot_node = ft_list_at(data->stack_a, pivot);
	while (data->stack_a->simplified_nmb != pivot_node->simplified_nmb)
	{
		rotates_end++;
		ft_rotate('a', data);
		ft_printf("ra\n");
	}
	while (end >= pivot)
	{
		end--;
		if (data->stack_a->simplified_nmb >= pivot_node->simplified_nmb)
		{
			ft_push('b', data);
			data->stack_b_size++;
		}
		else
		{
			rotates++;
			ft_rotate('a', data);
			print_necessary_pushes('a', data);
			ft_printf("ra\n");			
		}
	}
	while (data->stack_b)
	{
		ft_push('a', data);
		if (!data->stack_b_size)
			print_necessary_pushes('b', data);
		else
			data->stack_b_size--;
	}
	rotates_end = rotates_end + rotates;
	while (rotates_end)
	{
		rotates_end--;
		ft_printf("rra\n");
		ft_reverse_rotate('a', data);
	}
	new_pivot = pivot_node->simplified_nmb;
	return (new_pivot);
}

// pb
// pb
// ra
// ra
// pa
// pa
// rra
// rra
// pivot 0
// pivot node 2
// data node 1
// pivot 2
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
