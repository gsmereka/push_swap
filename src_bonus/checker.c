/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:26:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 21:57:53 by gsmereka         ###   ########.fr       */
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
			if (ft_strncmp(rule, data->rules_catalog[i], 3) == 0)
				create_new_rule(rule, data);
			i++;
		}
		free(rule);
		rule = get_next_line_clean(0, 0);
	}
	get_next_line_clean(0, 1);
	return (0);
}

void	apply_instructions(t_data *data)
{
	t_rule	*rule;

	rule = data->rules;
	while (rule)
	{
		if (ft_strncmp(rule->instruction, "pa\n", 3) == 0)
			ft_push('a', data);
		else if (ft_strncmp(rule->instruction, "pb\n", 3) == 0)
			ft_push('b', data);
		else if (ft_strncmp(rule->instruction, "sa\n", 3) == 0)
			ft_swap('a', data);
		else if (ft_strncmp(rule->instruction, "sb\n", 3) == 0)
			ft_swap('b', data);
		else if (ft_strncmp(rule->instruction, "ss\n", 3) == 0)
		{
			ft_swap('a', data);
			ft_swap('b', data);
		}
		else if (ft_strncmp(rule->instruction, "rra\n", 4) == 0)
			ft_reverse_rotate('a', data);
		else if (ft_strncmp(rule->instruction, "rrb\n", 4) == 0)
			ft_reverse_rotate('b', data);
		else if (ft_strncmp(rule->instruction, "rrr\n", 4) == 0)
		{
			ft_reverse_rotate('a', data);
			ft_reverse_rotate('b', data);
		}
		else if (ft_strncmp(rule->instruction, "ra\n", 3) == 0)
			ft_rotate('a', data);
		else if (ft_strncmp(rule->instruction, "rb\n", 3) == 0)
			ft_rotate('b', data);
		else if (ft_strncmp(rule->instruction, "rr\n", 3) == 0)
		{
			ft_rotate('a', data);
			ft_rotate('b', data);
		}
		rule = rule->next;
	}
}
