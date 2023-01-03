/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:26:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 20:08:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	get_instructions(t_data *data);

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

static void create_new_rule(void *rule, t_data *data)
{
	t_rule *new_rule;
	t_rule *last_node;

	new_rule = ft_calloc(1, sizeof(t_rule));
	if (!new_rule)
		return (NULL);
	new_rule->instruction = rule;
	new_rule->stack_a_size = data->stack_a_size;
	new_rule->stack_b_size = data->stack_b_size;
	new_rule->next = NULL;
	last_node = data->rules;
	if (!last_node)
		data->rules = new_rule;
	else
	{
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_rule;
	}
}

void	get_instructions(t_data *data)
{
	int		i;
	char	**operations;
	char	*rule;

	rule = get_next_line_clean(0, 0);
	while (rule)
	{

		rule = get_next_line_clean(0, 0);
	}
	get_next_line_clean(0, 1);
}

void	print_instructions(t_data *data)
{
	int		i;
	char	*rule;

	i = 1;
	while (i)
	{
		rule = get_next_line_clean(0, 0);
		if (!rule)
			break ;
		else if (ft_strncmp(rule, "pa\n", 3) == 0)
			ft_push('a', data);
		else if (ft_strncmp(rule, "pb\n", 3) == 0)
			ft_push('b', data);
		else if (ft_strncmp(rule, "sa\n", 3) == 0)
			ft_swap('a', data);
		else if (ft_strncmp(rule, "sb\n", 3) == 0)
			ft_swap('b', data);
		else if (ft_strncmp(rule, "ss\n", 3) == 0)
		{
			ft_swap('a', data);
			ft_swap('b', data);
		}
		else if (ft_strncmp(rule, "rra\n", 4) == 0)
			ft_reverse_rotate('a', data);
		else if (ft_strncmp(rule, "rrb\n", 4) == 0)
			ft_reverse_rotate('b', data);
		else if (ft_strncmp(rule, "rrr\n", 4) == 0)
		{
			ft_reverse_rotate('a', data);
			ft_reverse_rotate('b', data);
		}
		else if (ft_strncmp(rule, "ra\n", 3) == 0)
			ft_rotate('a', data);
		else if (ft_strncmp(rule, "rb\n", 3) == 0)
			ft_rotate('b', data);
		else if (ft_strncmp(rule, "rr\n", 3) == 0)
		{
			ft_rotate('a', data);
			ft_rotate('b', data);
		}
		else
		{
			free(rule);
			get_next_line_clean(0, 1);
			exit_error(1, data);
		}
		free(rule);
	}
	get_next_line_clean(0, 1);
}
