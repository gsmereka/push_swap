/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 20:22:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	is_previous_nmb_ok(t_data *data);

void	sort_small_list(t_data *data)
{
	while (!stack_a_is_sorted(data))
	{
		if (is_previous_nmb_ok(data))
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
}

static int	is_previous_nmb_ok(t_data *data)
{
	int		last_nmb;
	int		first_nmb;
	int		bigger_nmb;

	bigger_nmb = data->stack_a_size - 1;
	first_nmb = data->stack_a->simplified_nmb;
	last_nmb = (ft_list_at(data->stack_a,
				data->stack_a_size - 1))->simplified_nmb;
	if (first_nmb == 0 && last_nmb == bigger_nmb)
		return (1);
	if (first_nmb - 1 == last_nmb)
		return (1);
	return (0);
}
