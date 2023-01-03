/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 22:13:07 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 22:23:20 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static void	aplly_push_operation(char *instruction, t_data *data);
static void	aplly_swap_operation(char *instruction, t_data *data);
static void	aplly_rotate_operation(char *instruction, t_data *data);

void	apply_instructions(t_data *data)
{
	t_rule	*rule;

	rule = data->rules;
	while (rule)
	{
		if (rule->instruction[0] == 'p')
			aplly_push_operation(rule->instruction, data);
		if (rule->instruction[0] == 's')
			aplly_swap_operation(rule->instruction, data);
		if (rule->instruction[0] == 'r')
			aplly_rotate_operation(rule->instruction, data);
		rule = rule->next;
	}
}

static void	aplly_push_operation(char *instruction, t_data *data)
{
	if (ft_strncmp(instruction, "pa\n", 3) == 0)
		ft_push('a', data);
	if (ft_strncmp(instruction, "pb\n", 3) == 0)
		ft_push('b', data);
}

static void	aplly_swap_operation(char *instruction, t_data *data)
{
	if (ft_strncmp(instruction, "sa\n", 3) == 0)
		ft_swap('a', data);
	else if (ft_strncmp(instruction, "sb\n", 3) == 0)
		ft_swap('b', data);
	else if (ft_strncmp(instruction, "ss\n", 3) == 0)
	{
		ft_swap('a', data);
		ft_swap('b', data);
	}
}

static void	aplly_rotate_operation(char *instruction, t_data *data)
{
	if (ft_strncmp(instruction, "ra\n", 3) == 0)
		ft_rotate('a', data);
	else if (ft_strncmp(instruction, "rb\n", 3) == 0)
		ft_rotate('b', data);
	else if (ft_strncmp(instruction, "rr\n", 3) == 0)
	{
		ft_rotate('a', data);
		ft_rotate('b', data);
	}
	else if (ft_strncmp(instruction, "rra\n", 3) == 0)
		ft_reverse_rotate('a', data);
	else if (ft_strncmp(instruction, "rrb\n", 3) == 0)
		ft_reverse_rotate('b', data);
	else if (ft_strncmp(instruction, "rrr\n", 3) == 0)
	{
		ft_reverse_rotate('a', data);
		ft_reverse_rotate('b', data);
	}
}
