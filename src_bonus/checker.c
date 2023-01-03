/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:26:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 23:05:31 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	get_instructions(&data);
	apply_instructions(&data);
	check_if_is_sorted(&data);
	finalize(&data);
}
