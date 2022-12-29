/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_binary_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:36:06 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/28 21:48:38 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static char	*int_to_binary_char(int nmb);
static size_t	ft_calculate_size(unsigned long long n);

void	set_binary_values(t_list *stack)
{
	while (stack->next)
	{
		stack->binary_nmb = int_to_binary_char(stack->nmb);
		stack = stack->next;
	}
}
static size_t	ft_calculate_size(unsigned long long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*int_to_binary_char(int nmb)
{
	char	*str;
	size_t	size;

	if (nmb == 0)
		return (ft_strdup("0"));
	size = ft_calculate_size(nmb);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		if (nmb % 16 > 9)
			str[size - 1] = (nmb % 16) + 'a' - 10;
		else
			str[size - 1] = (nmb % 16) + '0';
		nmb = nmb / 16;
		size--;
	}
	return (str);
}
