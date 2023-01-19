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

static int	compare_absolute_values(char *nbr_copy, char *original_nbr);

int	check_if_is_numeric(char *arg, t_data *data)
{
	int	i;

	i = 0;
	while ((arg[i] >= '\t' && arg[i] <= '\r') || arg[i] == ' ')
		i++;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		exit_error(1, data);
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i] != '\0')
		exit_error(1, data);
	return (0);
}

int	check_integer_size(int nbr, char *original_nbr, t_data *data)
{
	char	*nbr_copy;
	int		diff;

	nbr_copy = ft_itoa(nbr);
	if (!nbr_copy)
		exit_error(12, data);
	diff = compare_absolute_values(nbr_copy, original_nbr);
	free(nbr_copy);
	if (diff != 0)
		exit_error(1, data);
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

int	check_integer_duplicates(int *int_list, int int_pos, t_data *data)
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
