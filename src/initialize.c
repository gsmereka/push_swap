/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:14 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/04 22:40:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	set_config(int argc, t_data *data);
static void	set_memory(int argc, t_data *data);

int	initialize(int argc, t_data *data)
{
	set_memory(argc, data);
	set_config(argc, data);
	return (0);
}

static void	set_config(int argc, t_data *data)
{
	data->stack_a_size = argc - 1;
	data->stack_b_size = 0;
	data->user_args = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

static void	set_memory(int argc, t_data *data)
{
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit_error(12, data);
	data->user_args = ft_calloc(argc, sizeof(int));
	if (!data->user_args)
		exit_error(12, data);
}
