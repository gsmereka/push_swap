/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 16:07:15 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sort_big_list(t_data *data)
{
	int	digit_pos;
	int	less_value_digit_pos;
	int	i;

	digit_pos = 1;
	while (digit_pos < 7)
	{
		i = 0;
		while (i < data->max_stack_size)
		{
			less_value_digit_pos = ft_strlen(data->stack_a->binary_nmb);
			less_value_digit_pos = less_value_digit_pos - digit_pos;
			if (data->stack_a->binary_nmb[less_value_digit_pos] == '0')
				ft_push('a', data);
			else
				ft_rotate('a', data);
			i++;
		}
		while (data->stack_b)
			ft_push('b', data);
		digit_pos++;
	}
	return (0);
}
