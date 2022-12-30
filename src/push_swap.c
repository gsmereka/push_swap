/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:04:43 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 17:49:23 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	init_sort(&data);
	finalize(&data);
}
