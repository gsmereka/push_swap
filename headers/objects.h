/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:02:22 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/08 23:30:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_list
{
	int				nmb;
	int				simplified_nmb;				
	char			*binary_nmb;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_rule
{
	char			*instruction;
	int				stack_a_size;
	int				stack_b_size;
	struct s_rule	*next;
}	t_rule;

typedef struct s_swap
{
	t_list	*first_node;
	t_list	*scond_node;
	t_list	*third_node;
}	t_swap;

typedef struct s_rotate
{
	t_list	*first_node;
	t_list	*scond_node;
	t_list	*penult_node;
	t_list	*last_node;
}	t_rotate;

typedef struct s_rule
{
	char			*instruction;
	struct s_rule	*next;
}	t_rule;

typedef struct s_data
{
	int				*user_args;
	int				stack_a_size;
	int				stack_b_size;
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	struct s_rule	*rules;
}	t_data;

#endif
