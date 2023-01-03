/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:29:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 19:59:34 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 1;
	if (!begin_list)
		return (-1);
	while (begin_list->next != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_list_at(t_list *begin_list, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (begin_list != NULL)
	{
		if (i == index)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	while (begin_list != NULL)
	{
		if (begin_list->next != NULL)
			begin_list = begin_list->next;
		else
			break ;
	}
	return (begin_list);
}
