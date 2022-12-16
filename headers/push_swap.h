/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:03:35 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/15 23:26:22 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./objects.h"
# include "./utils.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

// check_args
void	check_args(int argc);

// set_numbers
void	set_numbers(char **argv, t_data *data);

// set_numbers
void	set_stack(t_data *data);

// initialize
int		initialize(int argc, char **argv, t_data *data);

// execute

// finalize
void	exit_error(int error_type, t_data *data);
void	finalize(t_data *data);

#endif
