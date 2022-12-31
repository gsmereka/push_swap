/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 19:54:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

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
