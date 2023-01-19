/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:57:58 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/18 23:29:33 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	arg_to_integer(char *arg);
static void	check_args_amount(int argc, t_data *data);
static void	check_and_store_args(char **argv, t_data *data);

void	check_args(int argc, char **argv, t_data *data)
{
	check_args_amount(argc, data);
	check_and_store_args(argv, data);
}

static int	arg_to_integer(char *arg)
{
	int	sign;
	int	save;
	int	i;

	i = 0;
	while ((arg[i] >= '\t' && arg[i] <= '\r') || arg[i] == ' ')
		i++;
	save = 0;
	sign = 1;
	if (arg[i] == '-')
		sign = -1;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (ft_isdigit(arg[i]) > 0)
	{
		save = (save * 10) + (arg[i] - '0');
		i++;
	}
	return (save * sign);
}

static void	check_args_amount(int argc, t_data *data)
{
	if (argc <= 1)
		finalize(data);
}

static void	check_and_store_args(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		check_if_is_numeric(argv[i + 1], data);
		data->user_args[i] = arg_to_integer(argv[i + 1]);
		check_integer_size(data->user_args[i], argv[i + 1], data);
		check_integer_duplicates(data->user_args, i, data);
		i++;
	}
}
