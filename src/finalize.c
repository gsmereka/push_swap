/* ************************************************************************** */
/*						                                                    */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:18:39 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 22:29:56 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	free_program_memory(t_data *data);

void	exit_error(int error_type, t_data *data)
{
	free_program_memory(data);
	ft_putstr_fd("Error\n", 2);
	exit(error_type);
}

void	finalize(t_data *data)
{
	free_program_memory(data);
	exit(0);
}

static void	free_program_memory(t_data *data)
{
	ft_list_clear(data->stack_a);
	ft_list_clear(data->stack_b);
	free(data->user_args);
}
