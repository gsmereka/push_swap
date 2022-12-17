/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:02 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/17 14:34:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_numbers(int argc, t_data *data);
void	test_program(int argc, t_data *data);

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	check_args(argc);
	initialize(argc, argv, &data);
	set_numbers(argv, &data);
	set_stack(&data);
	test_program(argc, &data);
	finalize(&data);
}

void	print_numbers(int argc, t_data *data)
{
	t_list	*node_a;
	t_list	*node_b;
	int		i;

	i = 0;
	while (i < argc - 1)
	{
		node_a = ft_list_at(data->stack_a, i);
		node_b = ft_list_at(data->stack_b, i);
		if (node_a)
			ft_printf("%d ", node_a->nmb);
		else
			ft_printf("  ");
		if (node_b)
			ft_printf("%d ", node_b->nmb);
		ft_printf("\n");
		i++;
	}
}

void	test_program(int argc, t_data *data)
{
	int		i;
	char	*str;
	char	*help_msg;

	i = 1;
	help_msg = ft_strdup("Commands:\nexit: quit the program\nhelp: show the commands\npa: push a\npb: push b\nsa: swap a\nsb: swap b\nss: swap a & swap b");
	ft_printf("%s\n", help_msg);
	ft_printf("numbers:\n");
	print_numbers(argc, data);
	while (i)
	{
		ft_printf("Comand: ");
		str = get_next_line(0, 0);
		if (ft_strncmp(str, "exit", 4) == 0)
			break ;
		else if (ft_strncmp(str, "help", 4) == 0)
			ft_printf("%s\n", help_msg);
		else if (ft_strncmp(str, "pa", 2) == 0)
		{
			ft_push('a', data);
			ft_printf("push a:\n");
		}
		else if (ft_strncmp(str, "pb", 2) == 0)
		{
			ft_push('b', data);
			ft_printf("push b:\n");
		}
		else if (ft_strncmp(str, "sa", 2) == 0)
		{
			ft_swap('a', data);
			ft_printf("swap_a:\n");
		}
		else if (ft_strncmp(str, "sb", 2) == 0)
		{
			ft_swap('b', data);
			ft_printf("swap_b:\n");	
		}
		else if (ft_strncmp(str, "ss", 2) == 0)
		{
			ft_swap('a', data);
			ft_swap('b', data);
			ft_printf("swap_a & swap_b:\n");
		}
		else
			ft_printf("invalid command!\n(type 'help' if you forgot a command')\nnumbers:\n");	
		print_numbers(argc, data);
		free(str);
	}
	free(str);
	get_next_line(0, 1);
	free(help_msg);
}
