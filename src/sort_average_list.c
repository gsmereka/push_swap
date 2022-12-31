/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 17:17:17 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	stack_b_is_sorted(t_data *data);
static int	stack_a_is_sorted(t_data *data);
static void	print_necessary_pushes(int rules, t_data *data);
static void	push_entire_stack_b(t_data *data);

int	sort_average_list(t_data *data)
{
	int		smaller_nmb;
	int		last_nmb;
	int		first_nmb;

	smaller_nmb = 0;
	while (!stack_b_is_sorted(data))
	{
		first_nmb = data->stack_a->simplified_nmb;
		last_nmb = (ft_list_at(data->stack_a,
					data->stack_a_size - 1))->simplified_nmb;
		if (first_nmb == smaller_nmb)
		{
			ft_push('b', data);
			data->stack_b_size++;
			data->stack_a_size--;
			smaller_nmb++;
		}
		else if (last_nmb == smaller_nmb)
		{
			ft_reverse_rotate('a', data);
			print_necessary_pushes(1, data);
			ft_printf("rra\n");
		}
		else
		{
			ft_rotate('a', data);
			print_necessary_pushes(1, data);
			ft_printf("ra\n");
		}
		if (stack_a_is_sorted(data))
			break ;
	}
	push_entire_stack_b(data);
	return (0);
}

static void	print_necessary_pushes(int rules, t_data *data)
{
	if (rules == 1)
	{
		while (data->stack_b_size != 0)
		{
			ft_printf("pb\n");
			data->stack_b_size--;
		}
	}
	if (rules == 3)
		ft_printf("pa\n");
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

static void	push_entire_stack_b(t_data *data)
{
	while (data->stack_b)
	{
		ft_push('a', data);
		if (!data->stack_b_size)
			print_necessary_pushes(3, data);
		else
			data->stack_b_size--;
	}
}
