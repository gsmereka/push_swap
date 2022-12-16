/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:02 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/16 13:49:57 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_numbers(int argc, t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, argv, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	ft_swap('a', &data);
	print_numbers(argc, &data);
	finalize(&data);
}

void	print_numbers(int argc, t_data *data)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		node = ft_list_at(data->stack_a, i);
		ft_printf("%d\n", node->nmb);
		i++;
	}
}
