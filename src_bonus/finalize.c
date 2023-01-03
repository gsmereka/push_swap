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

#include "../headers/checker.h"

static void	free_program_memory(t_data *data);
static void	free_list_content(void *pointer);

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

static void	free_list_content(void *pointer)
{
	t_list	*list;

	list = (t_list *)pointer;
	if (list->binary_nmb)
		free (list->binary_nmb);
}

static void	free_program_memory(t_data *data)
{
	ft_list_clear(data->stack_a, free_list_content);
	ft_list_clear(data->stack_b, free_list_content);
	free(data->user_args);
}
