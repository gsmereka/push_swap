/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:32:14 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 21:36:39 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	set_config(int argc, t_data *data);
static void	set_memory(int argc, t_data *data);
static void	set_rules_catalog(t_data *data);

int	initialize(int argc, t_data *data)
{
	set_config(argc, data);
	set_memory(argc, data);
	set_rules_catalog(data);
	return (0);
}

static void	set_config(int argc, t_data *data)
{
	data->stack_a_size = argc - 1;
	data->stack_b_size = 0;
	data->user_args = NULL;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->rules_amount = 0;
}

static void	set_memory(int argc, t_data *data)
{
	data->user_args = ft_calloc(argc, sizeof(int));
	if (!data->user_args)
		exit_error(12, data);
	data->rules_catalog = ft_calloc(12, sizeof(char *));
	if (!data->rules_catalog)
		exit_error(12, data);
}

static void	set_rules_catalog(t_data *data)
{
	int	i;

	data->rules_catalog[0] = ft_strdup("pa\n");
	data->rules_catalog[1] = ft_strdup("pb\n");
	data->rules_catalog[2] = ft_strdup("sa\n");
	data->rules_catalog[3] = ft_strdup("sb\n");
	data->rules_catalog[4] = ft_strdup("ss\n");
	data->rules_catalog[5] = ft_strdup("ra\n");
	data->rules_catalog[6] = ft_strdup("rb\n");
	data->rules_catalog[7] = ft_strdup("rr\n");
	data->rules_catalog[8] = ft_strdup("rra\n");
	data->rules_catalog[9] = ft_strdup("rrb\n");
	data->rules_catalog[10] = ft_strdup("rrr\n");
	data->rules_catalog[11] = NULL;
	i = 0;
	while (i < 11)
	{
		if (!data->rules_catalog[i])
			exit_error(12, data);
		i++;
	}
}
