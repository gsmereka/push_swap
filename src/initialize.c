/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:14 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/15 10:01:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	set_config(int argc, t_data *data);
static void	set_memory(int argc, t_data *data);

int	initialize(int argc, char **argv, t_data *data)
{
	set_config(argc, data);
	set_memory(argc, data);
	return (0);
}

static void	set_config(int argc, t_data *data)
{
	data->numbers = NULL;
}

static void	set_memory(int argc, t_data *data)
{
	data->numbers = ft_calloc(argc, sizeof(int));
	if (!data->numbers)
		exit_error(12, data);
}
