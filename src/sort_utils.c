/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:15:57 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 18:13:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_sort_rules(char *rule, t_data *data)
{
	if (ft_strncmp(rule, "ra", 2) == 0)
	{
		print_necessary_pushes(1, data);
		ft_printf("ra\n");
	}
	if (ft_strncmp(rule, "rra", 3) == 0)
	{
		print_necessary_pushes(1, data);
		ft_printf("rra\n");
	}
}

void	print_necessary_pushes(int rules, t_data *data)
{
	if (rules == 1)
	{
		while (data->stack_b_size != 0)
		{
			ft_printf("pb\n");
			data->stack_b_size--;
		}
	}
	if (rules == 3)
	{
		ft_printf("pa\n");
	}
}
