/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 11:54:12 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	stack_a_is_sorted(t_data *data);

int	sort_small_list(t_data *data)
{
	int		last_nmb;
	int		first_nmb;

	while (!stack_a_is_sorted(data))
	{
		first_nmb = data->stack_a->simplified_nmb;
		last_nmb = (ft_list_at(data->stack_a, 2))->simplified_nmb;
		if ((first_nmb == 0 && last_nmb == 2) || (first_nmb - 1 == last_nmb))
		{
			ft_rotate('a', data);
			ft_printf("ra\n");
		}
		else
		{
			ft_swap('a', data);
			ft_printf("sa\n");
			if (stack_a_is_sorted(data))
				break ;
			ft_rotate('a', data);
			ft_printf("ra\n");
		}
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
