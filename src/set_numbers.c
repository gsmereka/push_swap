/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:57:58 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/17 19:12:17 by gsmereka         ###   ########.fr       */
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
	int	ptr_1;
	int	ptr_2;

	ptr_1 = 0;
	ptr_2 = 0;
	if (*nbr_copy == '-')
		ptr_1++;
	if (*original_nbr == '+' || *original_nbr == '-')
		ptr_2++;
	while (*original_nbr + ptr_2 == '0' && *original_nbr + 1 + ptr_2 != '\0')
		ptr_2++;
	diff = ft_strncmp(nbr_copy + ptr_1, original_nbr + ptr_2,
			ft_strlen(original_nbr + ptr_2));
	return (diff);
}
