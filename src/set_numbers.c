/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:57:58 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 16:33:27 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	arg_to_integer(char *arg, t_data *data);
static int	check_integer_size(int nbr, char *original_nbr, t_data *data);
static int	compare_absolute_values(char *nbr_copy, char *original_nbr);
static int	check_integer_duplicates(int *int_list, int int_pos, t_data *data);

void	set_numbers(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		data->user_args[i] = arg_to_integer(argv[i + 1], data);
		check_integer_size(data->user_args[i], argv[i + 1], data);
		check_integer_duplicates(data->user_args, i, data);
		i++;
	}
}

static int	arg_to_integer(char *arg, t_data *data)
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
	if (arg[i] != '\0')
	{
		ft_printf("'%s' is not an integrer\n", arg);
		exit_error(1, data);
	}
	return (save * sign);
}

static int	check_integer_size(int nbr, char *original_nbr, t_data *data)
{
	char	*nbr_copy;
	int		diff;

	nbr_copy = ft_itoa(nbr);
	if (!nbr_copy)
		exit_error(12, data);
	diff = compare_absolute_values(nbr_copy, original_nbr);
	free(nbr_copy);
	if (diff != 0)
	{
		ft_printf("Out of limit nbr: '%s'\n", original_nbr);
		exit_error(1, data);
	}
	return (0);
}

static int	compare_absolute_values(char *nbr_copy, char *original_nbr)
{
	int	diff;

	if ((*original_nbr != '-') && *nbr_copy == '-')
		return (-1);
	while ((*original_nbr >= '\t' && *original_nbr <= '\r')
		|| *original_nbr == ' ')
		original_nbr++;
	if (*original_nbr == '+' || *original_nbr == '-')
		original_nbr++;
	while (*original_nbr == '0' && *original_nbr + 1 != '\0')
		original_nbr++;
	if (*nbr_copy == '-')
		nbr_copy++;
	diff = ft_strncmp(nbr_copy, original_nbr,
			ft_strlen(original_nbr));
	return (diff);
}

static int	check_integer_duplicates(int *int_list, int int_pos, t_data *data)
{
	int	i;

	i = 0;
	while (i < int_pos)
	{
		if (int_list[i] == int_list[int_pos])
			exit_error(1, data);
		i++;
	}
	return (0);
}
