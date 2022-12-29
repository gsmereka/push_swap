/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:17:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/29 18:16:53 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	simplify_numbers(t_data *data);
static int	stack_a_is_sorted(t_data *data);

int	init_sort(t_data *data)
{
	if (stack_a_is_sorted(data))
		ft_printf("Ta certa\n");
	if (data->max_stack_size <= 5)
		sort_small_list(data);
	if (data->max_stack_size > 5)
	{
		simplify_numbers(data);
		sort_big_list(data);
	}
	return (0);
}

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
	ft_printf("Tested\n");
}
