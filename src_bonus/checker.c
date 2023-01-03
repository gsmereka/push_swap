/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:26:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 22:30:00 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	get_instructions(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	get_instructions(&data);
	apply_instructions(&data);
	check_if_is_sorted(&data);
	finalize(&data);
}

static int	create_new_rule(void *rule, t_data *data)
{
	t_rule	*new_rule;
	t_rule	*last_node;

	new_rule = ft_calloc(1, sizeof(t_rule));
	if (!new_rule)
		return (-1);
	new_rule->instruction = rule;
	new_rule->stack_a_size = data->stack_a_size;
	new_rule->stack_b_size = data->stack_b_size;
	new_rule->next = NULL;
	data->rules_amount++;
	last_node = data->rules;
	if (!last_node)
		data->rules = new_rule;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_rule;
	}
	return (0);
}

int	get_instructions(t_data *data)
{
	char	*rule;
	int		i;

	rule = get_next_line_clean(0, 0);
	while (rule)
	{
		i = 0;
		while (i < 12)
		{
			if (!data->rules_catalog)
				exit_error(1, data);
			if (ft_strncmp(rule, data->rules_catalog[i], 4) == 0)
				create_new_rule(rule, data);
			i++;
		}
		free(rule);
		rule = get_next_line_clean(0, 0);
	}
	get_next_line_clean(0, 1);
	return (0);
}
