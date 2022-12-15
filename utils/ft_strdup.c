/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 06:23:11 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/10 10:25:03 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

char	*ft_strdup(char *s)
{
	char	*dest;
	int		size;
	int		i;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char *));
		s[0] = '\0';
	}
	i = 0;
	size = ft_strlen(s);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
