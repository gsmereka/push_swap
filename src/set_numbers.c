/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:57:58 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/16 11:17:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static int	arg_to_int(char *arg, t_data *data);
static int	validate_number(int nbr, char *original_nbr, t_data *data);
static int	compare_absolute_values(char *nbr_copy, char *original_nbr);

void	set_numbers(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i + 1])
	{
		data->user_args[i] = arg_to_int(argv[i + 1], data);
		validate_number(data->user_args[i], argv[i + 1], data);
		i++;
	}
}

static int	arg_to_int(char *arg, t_data *data)
{
	int	sign;
	int	save;
	int	i;

	i = 0;
	save = 0;
	sign = 1;
	if (arg[i] == '-')
		sign = -1;
	if (arg[i] == '+' || arg[i] == '-' || ft_isdigit(arg[i]) > 0)
	{
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		while (ft_isdigit(arg[i]) > 0)
		{
			save = (save * 10) + (arg[i] - '0');
			i++;
		}
	}
	if (arg[i] != '\0' && ft_isdigit(arg[i]) == 0)
	{
		ft_printf("'%s' is not an integrer\n", arg);
		exit_error(1, data);
	}
	return (save * sign);
}

static int	validate_number(int nbr, char *original_nbr, t_data *data)
{
	char	*nbr_copy;
	int		diff;

	nbr_copy = ft_itoa(nbr);
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

	if (*nbr_copy == '-')
		*nbr_copy++;
	if (*original_nbr == '+' || *original_nbr == '-')
		*original_nbr++;
	while (*original_nbr == '0' && *original_nbr + 1 != '\0')
		*original_nbr++;
	diff = ft_strncmp(nbr_copy, original_nbr, ft_strlen(original_nbr));
	return (diff);
}
