/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_clean.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 02:24:40 by gsmereka          #+#    #+#             */
/*   Updated: 2023/01/08 22:53:05 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

static char	*ft_read(int fd, char *next_s);
static char	*ft_actual_s(char *str);
static char	*ft_define_next_s(char *str);
static int	ft_addstr(char **s1, char *s2);

char	*get_next_line_clean(int fd, int clean)
{
	char		*actual_s;
	static char	*next_s[1024];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	if (clean == 1)
	{
		free(next_s[fd]);
		next_s[fd] = NULL;
		return (NULL);
	}
	next_s[fd] = ft_read(fd, next_s[fd]);
	if (!next_s[fd])
		return (NULL);
	actual_s = ft_actual_s(next_s[fd]);
	next_s[fd] = ft_define_next_s(next_s[fd]);
	return (actual_s);
}

static char	*ft_read(int fd, char *next_s)
{
	char	*temp_s;
	int		stop;

	temp_s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_s)
		return (NULL);
	stop = 1;
	while (stop != 0 && !ft_strchr(next_s, '\n'))
	{
		stop = read(fd, temp_s, BUFFER_SIZE);
		if (stop == -1)
		{
			free(temp_s);
			return (NULL);
		}
		temp_s[stop] = '\0';
		ft_addstr(&next_s, temp_s);
	}
	free(temp_s);
	return (next_s);
}

static char	*ft_actual_s(char *s)
{
	char	*new_s;
	int		i;
	int		limit;

	if (s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i++;
	new_s = malloc((i + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	limit = 0;
	while (limit < i)
	{
		new_s[limit] = s[limit];
		limit++;
	}
	new_s[i] = '\0';
	return (new_s);
}

static char	*ft_define_next_s(char *s)
{
	char	*new_s;
	int		n_pos;
	int		new_end;

	n_pos = 0;
	while (s[n_pos] != '\0' && s[n_pos] != '\n')
		n_pos++;
	if (s[n_pos] == '\0')
	{
		free(s);
		return (NULL);
	}
	n_pos++;
	new_s = (char *)malloc((1 + (ft_strlen(s) - n_pos)) * sizeof(char));
	if (new_s == NULL)
	{
		free(s);
		return (NULL);
	}
	new_end = 0;
	while (s[n_pos] != '\0')
		new_s[new_end++] = s[n_pos++];
	new_s[new_end] = '\0';
	free(s);
	return (new_s);
}

static int	ft_addstr(char **s1, char *s2)
{
	char	*new_s;
	int		s1_size;
	int		s2_size;
	int		i;

	if (*s1 == NULL)
		*s1 = ft_strdup("");
	if (*s1 == NULL || !s2)
		return (-1);
	s1_size = ft_strlen(*s1);
	s2_size = ft_strlen(s2);
	new_s = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	if (new_s == NULL)
		return (-1);
	i = -1;
	while (++i < (s1_size + s2_size + 1))
	{
		if (i < s1_size)
			new_s[i] = (*s1)[i];
		else
			new_s[i] = s2[i - s1_size];
	}
	free(*s1);
	*s1 = new_s;
	return (0);
}
