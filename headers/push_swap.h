/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:35 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/31 21:07:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./objects.h"
# include "./utils.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

// check_args
void	check_args(int argc);

// set_numbers
void	set_numbers(char **argv, t_data *data);

// set_stack
void	set_stack(t_data *data);

// set_binary_values
void	set_binary_values(t_list *stack, t_data *data);

// initialize
int		initialize(int argc, t_data *data);

// sort_utils
void	print_necessary_pushes(int rules, t_data *data);
int		stack_a_is_sorted(t_data *data);
int		stack_b_is_sorted(t_data *data);

// init_sort
int		init_sort(t_data *data);

// sort_list
void	sort_small_list(t_data *data);
void	sort_average_list(t_data *data);
void	sort_big_list(t_data *data);

// finalize
void	exit_error(int error_type, t_data *data);
void	finalize(t_data *data);

// list_utils_1
t_list	*ft_create_elem(int nmb);
void	ft_list_clear(t_list *begin_list, void (*fre_function)(void *));
void	ft_list_push_back(t_list **begin_list, int nmb);

// list_utils_2
t_list	*ft_list_at(t_list *begin_list, unsigned int index);
int		ft_list_size(t_list *begin_list);
t_list	*ft_list_last(t_list *begin_list);

// swaps
int		ft_swap(char stack_c, t_data *data);
int		ft_push(char stack_c, t_data *data);
int		ft_rotate(char stack_c, t_data *data);
int		ft_reverse_rotate(char stack_c, t_data *data);

#endif
