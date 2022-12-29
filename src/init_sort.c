/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:17:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/29 17:59:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void simplify_numbers(t_data *data);

int	init_sort(t_data *data)
{
	if (data->max_stack_size <= 5)
		sort_small_list(data);
	if (data->max_stack_size > 5)
	{
		simplify_numbers(data);
		sort_big_list(data);
	}
	return (0);
}

static void simplify_numbers(t_data *data)
{
	ft_printf("Tested\n");
}
