/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_binary_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:36:06 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/30 14:13:07 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static char		*int_to_binary_char(int nmb);
static size_t	ft_calculate_size(unsigned long long n);

void	set_binary_values(t_list *stack, t_data *data)
{
	while (stack)
	{
		stack->binary_nmb = int_to_binary_char(stack->simplified_nmb);
		if (!stack->binary_nmb)
			exit_error(12, data);
		stack = stack->next;
	}
}

static size_t	ft_calculate_size(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 2;
		i++;
	}
	return (i);
}

static char	*int_to_binary_char(int nmb)
{
	char	*str;
	size_t	size;

	if (nmb == 0)
		return (ft_strdup("0000"));
	size = ft_calculate_size(nmb);
	size = 4;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		if (nmb % 2)
			str[size - 1] = '1';
		else
			str[size - 1] = '0';
		nmb = nmb / 2;
		size--;
	}
	return (str);
}
