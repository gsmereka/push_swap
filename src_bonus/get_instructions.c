/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 23:05:35 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/03 00:19:11 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static int	add_rule_to_data(void *rule, t_data *data);
static int	validate_rule(char **rule, t_data *data);

int	get_instructions(t_data *data)
{
	char	*rule;
	int		i;

	i = 0;
	while (i >= 0)
	{
		i = 0;
		rule = get_next_line_clean(0, 0);
		if (!rule)
			break ;
		validate_rule(&rule, data);
		add_rule_to_data(rule, data);
	}
	get_next_line_clean(0, 1);
	return (0);
}

static int	validate_rule(char **rule, t_data *data)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(*rule, data->rules_catalog[i], 4) == 0)
		{
			add_rule_to_data(*rule, data);
			return (0);
		}
		i++;
	}
	free(*rule);
	get_next_line_clean(0, 1);
	exit_error(1, data);
	return (-1);
}

static int	add_rule_to_data(void *rule, t_data *data)
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
