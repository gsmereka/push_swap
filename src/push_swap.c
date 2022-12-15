/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:02 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/15 10:00:19 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_numbers(int argc, t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc, argv, &data);
	initialize(argc, argv, &data);
	set_numbers(argv, &data);
	print_numbers(argc, &data);
	finalize(&data);
}

void	print_numbers(int argc, t_data *data)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", data->numbers[i]);
		i++;
	}
}
