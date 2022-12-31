/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:27:29 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 16:16:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	init_stack_variables(t_list *node);

void	set_stack(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->stack_a_size)
	{
		ft_list_push_back(&data->stack_a, data->user_args[i]);
		i++;
	}
	init_stack_variables(data->stack_a);
}

static void	init_stack_variables(t_list *node)
{
	if (node)
	{
		init_stack_variables(node->next);
		node->binary_nmb = NULL;
	}
}
