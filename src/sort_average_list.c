/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 16:01:00 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	stack_b_is_sorted(t_data *data);
static int	stack_a_is_sorted(t_data *data);
static void	print_rules(int rules, t_data *data);

int	sort_average_list(t_data *data)
{
	int		smaller_nmb;
	int		last_nmb;
	int		first_nmb;

	smaller_nmb = 0;
	data->pa_count = 0;
	while(!stack_b_is_sorted(data))
	{
		first_nmb = data->stack_a->simplified_nmb;
		last_nmb = (ft_list_at(data->stack_a, data->max_stack_size - 1))->simplified_nmb;
		if (first_nmb == smaller_nmb)
		{
			ft_push('b', data);
			data->pa_count++;
			smaller_nmb++;
			data->max_stack_size--;
		}
		else if (last_nmb == smaller_nmb)
		{
			ft_reverse_rotate('a', data);
			print_rules(1, data);
		}
		else
		{
			ft_rotate('a', data);
			print_rules(2, data);
		}
		if (stack_a_is_sorted(data))
			break ;
	}
	while(data->stack_b)
	{
		ft_push('a', data);
		data->max_stack_size++;
		if (!data->pa_count)
			print_rules(3, data);
		else
			data->pa_count--;
	}
	// print_simplified_numbers(data);
	return (0);
}

static void	print_rules(int rules, t_data *data)
{
	int ok;

	ok = 0;
	if (rules == 2)
	{
		while (data->pa_count != 0)
		{
			ft_printf("pb\n");
			if (ok)
				print_simplified_numbers(data);
			data->pa_count--;
		}
		ft_printf("ra\n");
		if (ok)
			print_simplified_numbers(data);
	}
	if (rules == 1)
	{
		while (data->pa_count != 0)
		{
			ft_printf("pb\n");
			if (ok)
				print_simplified_numbers(data);
			data->pa_count--;
		}
		ft_printf("rra\n");
		if (ok)
			print_simplified_numbers(data);
	}
	if (rules == 3)
	{
		ft_printf("pa\n");
		if (ok)
			print_simplified_numbers(data);
	}
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

static int	stack_b_is_sorted(t_data *data)
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
