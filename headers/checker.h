/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:22:00 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 13:08:37 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./objects.h"
# include "./utils.h"
# include "./push_swap.h"
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

// GNL
char	*get_next_line_clean(int fd, int clean);

#endif
