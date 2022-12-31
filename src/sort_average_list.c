/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 19:46:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	merge_stacks(t_data *data);
static void	print_sort_rules(char *rule, t_data *data);
static int	sort_and_check_sorting_rules(int smaller_nmb,
				int first_nmb, int last_nmb, t_data *data);

void	sort_average_list(t_data *data)
{
	int		smaller_nmb;
	int		last_nmb;
	int		first_nmb;

	smaller_nmb = 0;
	last_nmb = 0;
	first_nmb = 0;
	sort_and_check_sorting_rules(smaller_nmb, first_nmb, last_nmb, data);
	merge_stacks(data);
}

static int	sort_and_check_sorting_rules(int smaller_nmb,
				int first_nmb, int last_nmb, t_data *data)
{
	while (!stack_b_is_sorted(data))
	{
		first_nmb = data->stack_a->simplified_nmb;
		last_nmb = (ft_list_at(data->stack_a,
					data->stack_a_size - 1))->simplified_nmb;
		if (first_nmb == smaller_nmb)
		{
			ft_push('b', data);
			data->stack_b_size++;
			data->stack_a_size--;
			smaller_nmb++;
		}
		else if (last_nmb == smaller_nmb)
		{
			ft_reverse_rotate('a', data);
			print_sort_rules("rra", data);
		}
		else
		{
			ft_rotate('a', data);
			print_sort_rules("ra", data);
		}
	}
	return (0);
}

static void	print_sort_rules(char *rule, t_data *data)
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

static void	merge_stacks(t_data *data)
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
