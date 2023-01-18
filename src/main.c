/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:04:43 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/18 20:05:05 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	initialize(argc, &data);
	check_args(argv, &data);
	set_stack(&data);
	init_sort(&data);
	finalize(&data);
}
