/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:26:17 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 13:48:43 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

void	get_instructions(t_data *data);

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	ft_printf("OK\n");
	get_instructions(&data);
	finalize(&data);
}

void	get_instructions(t_data *data)
{
	int		i;
	char	*str;

	i = 1;
	while (i)
	{
		str = get_next_line_clean(0, 0);
		if (!str)
			finalize(data);
		else if (ft_strncmp(str, "pa\n", 3) == 0)
			ft_push('a', data);
		else if (ft_strncmp(str, "pb\n", 3) == 0)
			ft_push('b', data);
		else if (ft_strncmp(str, "sa\n", 3) == 0)
			ft_swap('a', data);
		else if (ft_strncmp(str, "sb\n", 3) == 0)
			ft_swap('b', data);
		else if (ft_strncmp(str, "ss\n", 3) == 0)
		{
			ft_swap('a', data);
			ft_swap('b', data);
		}
		else if (ft_strncmp(str, "rra\n", 4) == 0)
			ft_reverse_rotate('a', data);
		else if (ft_strncmp(str, "rrb\n", 4) == 0)
			ft_reverse_rotate('b', data);
		else if (ft_strncmp(str, "rrr\n", 4) == 0)
		{
			ft_reverse_rotate('a', data);
			ft_reverse_rotate('b', data);
		}
		else if (ft_strncmp(str, "ra\n", 3) == 0)
			ft_rotate('a', data);
		else if (ft_strncmp(str, "rb\n", 3) == 0)
			ft_rotate('b', data);
		else if (ft_strncmp(str, "rr\n", 3) == 0)
		{
			ft_rotate('a', data);
			ft_rotate('b', data);
		}
		else
			ft_printf("KO\n");
		free(str);
	}
	get_next_line_clean(0, 1);
}
