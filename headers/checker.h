/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 12:22:00 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/02 12:46:46 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./objects.h"
# include "./utils.h"
# include <stdlib.h>
# include <unistd.h>

// GNL
char	*get_next_line_clean(int fd, int clean);

#endif
