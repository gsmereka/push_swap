/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:16:31 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/16 12:44:29 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

int    ft_swap(t_list *stack, t_data *data)
{
    t_list  *first_node;
    t_list  *scond_node;
    t_list  *third_node;
    int     size;

    size = ft_list_size(stack);
    if (size <= 1)
        return (0);
    first_node = stack->next;
    scond_node = stack;
    third_node = stack->next->next;
    ft_printf("TAMANHP:%d\n", first_node->nmb);
    ft_printf("TAMANHP:%d\n", scond_node->nmb);
    ft_printf("TAMANHP:%d\n", third_node->nmb);
    first_node->prev = NULL;
    scond_node->prev = first_node;
    ft_printf("TAMANHP:%d\n", scond_node->prev->next->nmb);
    scond_node->next = third_node;
    first_node->next = scond_node;
    // ft_printf("TAMANHooo:%d\n", first_node->next->nmb);
    // scond_node->prev = first_node;
    // scond_node->next = first_node->next;
    // stack = first_node;
}
