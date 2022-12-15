/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:29:17 by gsmereka          #+#    #+#             */
/*   Updated: 2022/12/15 16:44:32 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

t_list *ft_list_push_strs(int size, char **strs)
{
    t_list  *node;
    int     i;

    i = 0;
    node = NULL;
    while (i < size)
    {
        ft_list_push_back(&node, ft_strdup(strs[i]));
        i++;
    }
    return (node);
}

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    if (begin_list != NULL)
    {
        ft_list_clear(begin_list->next, free_fct);
        free_fct(begin_list);
        free(begin_list);
    }
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int    i;

    i = 0;
    while (begin_list != NULL)
    {
        if (!begin_list->next || i == nbr)
            return (begin_list);
        begin_list = begin_list->next;
        i++;
    }
    return (begin_list);
}

void ft_list_reverse(t_list **begin_list)
{
    t_list *new_list;
    t_list *save;
    int     i;

    if (*begin_list != NULL)
    {
        i = ft_list_size(*begin_list) - 2;
        new_list = ft_list_last(*begin_list);
        save = new_list;
        while (i >= 0)
        {
            new_list->next = ft_list_at(*begin_list, i);
            new_list = new_list->next;
            i--;
        }
        new_list->next = NULL;
        *begin_list = save;
    }
}
