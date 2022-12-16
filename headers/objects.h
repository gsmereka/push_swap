/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:02:22 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/16 15:17:14 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_list
{
	int				nmb;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_swap
{
	t_list	*first_node;
	t_list	*scond_node;
	t_list	*third_node;
}	t_swap;

typedef struct s_data
{
	int				*user_args;
	int				max_stack_size;
	struct s_list	*stack_a;
	struct s_list	*stack_b;
}	t_data;

#endif
