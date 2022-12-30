/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 15:25:39 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sort_big_list(t_data *data)
{
	int	increment_digit_value;
	int	less_value_digit;
	int	i;

	increment_digit_value = 1;
	while (increment_digit_value < 5)
	{
		i = 0;
		while (i < data->max_stack_size)
		{
			less_value_digit = ft_strlen(data->stack_a->binary_nmb) - increment_digit_value;
			if (data->stack_a->binary_nmb[less_value_digit] == '0')
				ft_push('a', data);
			else
				ft_rotate('a', data);
			i++;
		}
		while (data->stack_b)
			ft_push('b', data);
		increment_digit_value++;
	}
	return (0);
}
