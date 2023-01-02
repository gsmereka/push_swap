/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:06:29 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 18:54:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_list	*ft_create_elem(int nmb)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->nmb = nmb;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	ft_list_push_back(t_list **begin_list, int nmb)
{
	t_list	*last_node;
	t_list	*new_node;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(nmb);
	else
	{
		last_node = ft_list_last(*begin_list);
		new_node = ft_create_elem(nmb);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	ft_list_clear(t_list *begin_list, void (*free_function)(void *))
{
	if (begin_list != NULL)
	{
		ft_list_clear(begin_list->next, free_function);
		free_function(begin_list);
		free(begin_list);
	}
}
