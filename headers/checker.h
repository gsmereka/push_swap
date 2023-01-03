/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:22:00 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 22:13:42 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./objects.h"
# include "./utils.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

// apply instructions
void	apply_instructions(t_data *data);

// check if is sorted
void	check_if_is_sorted(t_data *data);

// check_args
void	check_args(int argc);

// set_numbers
void	set_numbers(char **argv, t_data *data);

// set_stack
void	set_stack(t_data *data);

// initialize
int		initialize(int argc, t_data *data);

// finalize
void	exit_error(int error_type, t_data *data);
void	finalize(t_data *data);

// GNL
char	*get_next_line_clean(int fd, int clean);

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
