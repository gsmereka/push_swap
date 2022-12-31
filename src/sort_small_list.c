/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:32:52 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 01:30:23 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_numbers(t_data *data);
static void	print_simplified_numbers(t_data *data);
void	test_program(t_data *data);
static int	stack_a_is_sorted(t_data *data);

int	sort_small_list(t_data *data)
{
	t_list	*first_node;
	t_list	*last_node;
	int		i;

	i = 0;
	// test_program(data);
	// last_node = ft_list_at(first_node, data->max_stack_size - 1);
	// ft_printf("%d\n", last_node->nmb);
	// finalize(data);
	// print_simplified_numbers(data);
	while(stack_a_is_sorted(data))
	// while (i < 10)
	{
		first_node = data->stack_a;
		last_node = ft_list_at(first_node, data->max_stack_size - 1);
		if (first_node->simplified_nmb == 0 && last_node->simplified_nmb != 4)
		{
			ft_swap('a', data);
			ft_printf("sa\n");
			// print_simplified_numbers(data);
		}
		else if ((last_node->simplified_nmb != first_node->simplified_nmb - 1)
				&& (first_node->simplified_nmb != 0 && last_node->simplified_nmb != 4))
		{
			ft_swap('a', data);
			ft_printf("sa\n");
			// print_simplified_numbers(data);
		}
		if (!stack_a_is_sorted(data))
			break ;
		ft_rotate('a', data);
		ft_printf("ra\n");
		// print_simplified_numbers(data);
		i++;
	}
	// test_program(data);
	// print_simplified_numbers(data);
	finalize(data);
	return (0);
}

static void	print_simplified_numbers(t_data *data)
{
	t_list	*node_a;
	int		i;

	i = 0;
	ft_printf("Valor simplificado   binario  Numero passado\n");
	while (i < data->max_stack_size)
	{
		node_a = ft_list_at(data->stack_a, i);
		if (node_a)
		{
			ft_printf("       %d ", node_a->simplified_nmb);
			ft_printf("             %s ", node_a->binary_nmb);
			ft_printf("           %d ", node_a->nmb);
			ft_printf("\n");
		}
		i++;
	}
}

static int	stack_a_is_sorted(t_data *data)
{
	t_list	*node;

	node = data->stack_a;
	while (node->next)
	{
		if (node->nmb > node->next->nmb)
			return (1);
		node = node->next;
	}
	return (0);
}

void	print_numbers(t_data *data)
{
	t_list	*node_a;
	t_list	*node_b;
	int		i;

	i = 0;
	while (i < data->max_stack_size)
	{
		node_a = ft_list_at(data->stack_a, i);
		node_b = ft_list_at(data->stack_b, i);
		if (node_a)
			ft_printf("%d ", node_a->simplified_nmb);
		else
			ft_printf("  ");
		if (node_b)
			ft_printf("%d ", node_b->simplified_nmb);
		ft_printf("\n");
		i++;
	}
}

void	test_program(t_data *data)
{
	int		i;
	char	*str;
	char	*help_msg;

	i = 1;
	help_msg = ft_strdup("Commands:\nexit: quit the program\nhelp: show the commands\npa: push a\npb: push b\nsa: swap a\nsb: swap b\nss: swap a & swap b\nra: rotate a\nrb: rotate b\nrr: rotate a & b\nrra: reverse rotate a\nrrb: reverse rotate b\nrrr: reverse rotate a & b");
	ft_printf("%s\n", help_msg);
	ft_printf("numbers:\n");
	print_numbers(data);
	while (i)
	{
		ft_printf("Comand: ");
		str = get_next_line(0, 0);
		if (!str)
			break ;
		if (ft_strncmp(str, "exit\n", 5) == 0)
			break ;
		else if (ft_strncmp(str, "help\n", 5) == 0)
			ft_printf("%s\n", help_msg);
		else if (ft_strncmp(str, "pa\n", 3) == 0)
		{
			ft_push('a', data);
			ft_printf("push a:\n");
		}
		else if (ft_strncmp(str, "pb\n", 3) == 0)
		{
			ft_push('b', data);
			ft_printf("push b:\n");
		}
		else if (ft_strncmp(str, "sa\n", 3) == 0)
		{
			ft_swap('a', data);
			ft_printf("swap_a:\n");
		}
		else if (ft_strncmp(str, "sb\n", 3) == 0)
		{
			ft_swap('b', data);
			ft_printf("swap_b:\n");	
		}
		else if (ft_strncmp(str, "ss\n", 3) == 0)
		{
			ft_swap('a', data);
			ft_swap('b', data);
			ft_printf("swap_a & swap_b:\n");
		}
		else if (ft_strncmp(str, "rra\n", 4) == 0)
		{
			ft_reverse_rotate('a', data);
			ft_printf("reverse rotate a\n");
		}
		else if (ft_strncmp(str, "rrb\n", 4) == 0)
		{
			ft_reverse_rotate('b', data);
			ft_printf("reverse rotate b:\n");
		}
		else if (ft_strncmp(str, "rrr\n", 4) == 0)
		{
			ft_reverse_rotate('a', data);
			ft_reverse_rotate('b', data);
			ft_printf("reverse rotate a & b:\n");
		}
		else if (ft_strncmp(str, "ra\n", 3) == 0)
		{
			ft_rotate('a', data);
			ft_printf("rotate a\n");
		}
		else if (ft_strncmp(str, "rb\n", 3) == 0)
		{
			ft_rotate('b', data);
			ft_printf("rotate b:\n");
		}
		else if (ft_strncmp(str, "rr\n", 3) == 0)
		{
			ft_rotate('a', data);
			ft_rotate('b', data);
			ft_printf("rotate a & rotate b:\n");
		}
		else
			ft_printf("invalid command!\n(type 'help' if you forgot a command')\nnumbers:\n");
		print_numbers(data);
		free(str);
	}
	if (str)
		free(str);
	get_next_line(0, 1);
	free(help_msg);
}
