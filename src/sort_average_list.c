/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 20:38:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	reverse_sort_stack_b(t_data *data);
static void	pull_stack_b(t_data *data);
static int	last_nmb(t_data *data);
static void	print_sorting_rules(char *rule, t_data *data);

void	sort_average_list(t_data *data)
{
	reverse_sort_stack_b(data);
	pull_stack_b(data);
}

static void	reverse_sort_stack_b(t_data *data)
{
	int	first_nmb;
	int	smaller_nmb;

	smaller_nmb = 0;
	while (!stack_b_is_sorted(data))
	{
		first_nmb = data->stack_a->simplified_nmb;
		if (first_nmb == smaller_nmb)
		{
			ft_push('b', data);
			data->stack_b_size++;
			data->stack_a_size--;
			smaller_nmb++;
		}
		else if (last_nmb(data) == smaller_nmb)
		{
			ft_reverse_rotate('a', data);
			print_sorting_rules("rra", data);
		}
		else
		{
			ft_rotate('a', data);
			print_sorting_rules("ra", data);
		}
	}
}

static void	print_sorting_rules(char *rule, t_data *data)
{
	if (ft_strncmp(rule, "ra", 2) == 0)
	{
		print_necessary_pushes('a', data);
		ft_printf("ra\n");
	}
	if (ft_strncmp(rule, "rra", 3) == 0)
	{
		print_necessary_pushes('a', data);
		ft_printf("rra\n");
	}
}

static void	pull_stack_b(t_data *data)
{
	while (data->stack_b)
	{
		ft_push('a', data);
		if (!data->stack_b_size)
			print_necessary_pushes('b', data);
		else
			data->stack_b_size--;
	}
}

static int	last_nmb(t_data *data)
{
	t_list	*last_node;
	int		last_nmb;

	last_node = ft_list_at(data->stack_a, data->stack_a_size - 1);
	last_nmb = last_node->simplified_nmb;
	return (last_nmb);
}
