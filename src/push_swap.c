/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:02 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/17 12:53:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_numbers(int argc, t_data *data);
void	test_program(int argc, t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, argv, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	ft_printf("original:\n");
	print_numbers(argc, &data);
	test_program(argc, &data);
	finalize(&data);
}

void	print_numbers(int argc, t_data *data)
{
	t_list	*node_a;
	t_list	*node_b;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		node_a = ft_list_at(data->stack_a, i);
		if (node_a)
			ft_printf("%d ", node_a->nmb);
		else
			ft_printf("  ");
		node_b = ft_list_at(data->stack_b, i);
		if (node_b)
			ft_printf("%d ", node_b->nmb);
		ft_printf("\n");
		i++;
	}
}

void	test_program(int argc, t_data *data)
{
	ft_swap('a', data);
	ft_printf("swap_a:\n");
	print_numbers(argc, data);
	ft_push('a', data);
	ft_printf("push_a:\n");
	print_numbers(argc, data);
	ft_push('a', data);
	ft_printf("push_a:\n");
	print_numbers(argc, data);
	ft_push('b', data);
	ft_printf("push_b:\n");
	print_numbers(argc, data);
	ft_push('b', data);
	ft_printf("push_b:\n");
	print_numbers(argc, data);
	ft_push('b', data);
	ft_printf("push_b:\n");
	print_numbers(argc, data);
}
