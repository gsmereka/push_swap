/* ************************************************************************** */
/*                                                                          */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:10:10 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 17:39:59 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	check_args_amount(int argc);

void	check_args(int argc)
{
	check_args_amount(argc);
}

static void	check_args_amount(int argc)
{
	char	*error_msg;

	if (argc < 2)
	{
		error_msg = ft_strdup("push_swap needs a list of integers\ntry "
				"\'./push_swap nmb_1 nmb_2 nmb_3...\'\n");
		write(2, error_msg, ft_strlen(error_msg));
		free(error_msg);
		exit(2);
	}
}
