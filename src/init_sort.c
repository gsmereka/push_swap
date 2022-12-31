/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:17:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 01:06:18 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	simplify_numbers(t_data *data);
static int	stack_a_is_sorted(t_data *data);

static void	print_simplified_numbers(t_data *data);

int	init_sort(t_data *data)
{
	// print_simplified_numbers(data);
	if (stack_a_is_sorted(data))
		return (0);
	simplify_numbers(data);
	set_binary_values(data->stack_a, data);
	if (data->max_stack_size <= 5)
		sort_small_list(data);
	if (data->max_stack_size > 5)
		sort_big_list(data);
	// print_simplified_numbers(data);
	return (0);
}

// se o ultimo estiver errado, gira e troca
static int	stack_a_is_sorted(t_data *data)
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

static void	print_simplified_numbers(t_data *data)
{
	t_list	*node_a;
	int		i;

	i = 0;
	ft_printf("Valor simplificado   binario  Numero passado\n");
	while (i < data->max_stack_size)
	{
		node_a = ft_list_at(data->stack_a, i);
		if (node_a)
		{
			ft_printf("       %d ", node_a->simplified_nmb);
			ft_printf("             %s ", node_a->binary_nmb);
			ft_printf("           %d ", node_a->nmb);
			ft_printf("\n");
		}
		i++;
	}
}
