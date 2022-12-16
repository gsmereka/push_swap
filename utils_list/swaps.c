/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:16:31 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/16 13:52:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

int	ft_swap(char stack, t_data *data)
{
	t_list	*node;
	t_list	*first_node;
	t_list	*scond_node;
	t_list	*third_node;
	int		size;

	if (stack == 'a')
		node = data->stack_a;
	if (stack == 'b')
		node = data->stack_b;
	if (ft_list_size(node) <= 1)
		return (0);
	first_node = node->next;
	scond_node = node;
	third_node = node->next->next;
	first_node->prev = NULL;
	scond_node->prev = first_node;
	first_node->next = scond_node;
	scond_node->next = third_node;
	if (third_node != NULL)
		third_node->prev = scond_node;
	if (stack == 'a')
		data->stack_a = first_node;
	if (stack == 'b')
		data->stack_b = first_node;
}
