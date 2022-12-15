/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:24:31 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/16 16:11:35 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

static	size_t	ft_subs_size(size_t s_size, size_t start, size_t len)
{
	unsigned int	subs_size;

	if (start < s_size)
	{
		subs_size = s_size - start;
	}
	if (start >= s_size)
	{
		subs_size = 0;
	}
	if (subs_size > len)
	{
		subs_size = len;
	}
	return (subs_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	subs_size;
	size_t	s_size;

	if (!s)
		return (NULL);
	s_size = ft_strlen(s);
	subs_size = ft_subs_size(s_size, start, len);
	subs = (char *)ft_calloc(subs_size + 1, sizeof(char));
	if (!subs)
		return (NULL);
	if (subs_size == 0)
		subs[0] = 0;
	else
		ft_strlcpy (subs, &s[start], subs_size + 1);
	return (subs);
}
