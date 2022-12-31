/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:14 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 16:16:08 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	set_config(int argc, t_data *data);
static void	set_memory(int argc, t_data *data);

int	initialize(int argc, t_data *data)
{
	set_config(argc, data);
	set_memory(argc, data);
	return (0);
}

static void	set_config(int argc, t_data *data)
{
	data->stack_a_size = argc - 1;
	data->user_args = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
}

static void	set_memory(int argc, t_data *data)
{
	data->user_args = ft_calloc(argc, sizeof(int));
	if (!data->user_args)
		exit_error(12, data);
}
