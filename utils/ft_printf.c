/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 04:54:14 by gsmereka          #+#    #+#             */
/*   Updated: 2022/11/28 16:42:20 by gsmereka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"

static char	*ft_ptr_adr(char *word)
{
	char	*temp_w;

	temp_w = ft_strdup(word);
	free(word);
	if (temp_w[0] == '0' && ft_strlen(temp_w) == 1)
		word = ft_strdup("(nil)");
	else
	{
		word = ft_strdup("0x");
		word = ft_strjoin(word, temp_w);
	}
	free(temp_w);
	return (word);
}

static char	*ft_unsignedworks(const char *s, unsigned long long n)
{
	char	*word;
	int		i;

	i = 1;
	word = NULL;
	if (s[i] == 'x' || s[i] == 'X')
	{
		word = ft_itohex((unsigned int)n);
		if (s[i] == 'X')
		{
			i = 0;
			while (word[i++])
				word[i - 1] = ft_toupper(word[i - 1]);
		}
	}
	else if (s[i] == 'p')
	{
		word = ft_itohex(n);
		word = ft_ptr_adr(word);
	}
	else if (s[i] == 'u')
		word = ft_utoa((unsigned int)n);
	return (word);
}

static int	ft_printchar(va_list args, char c)
{
	if (c == '%' || c == 'c')
	{
		if (c == '%')
			ft_putchar_fd('%', 1);
		else
			ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	return (0);
}

static int	ft_atow(const char *s, va_list args)
{
	int		i;
	char	*word;

	i = 1;
	if (ft_strchr("cspdiuxX%", s[i]) == NULL)
		return (1);
	if (ft_printchar(args, s[i]) == 1)
		return (1);
	if (s[i] == 's')
	{
		word = NULL;
		word = va_arg(args, char *);
		if (!word)
			word = ft_strdup("(null)");
		else
			word = ft_strdup(word);
	}
	if (s[i] == 'd' || s[i] == 'i')
		word = ft_itoa(va_arg(args, int));
	if (s[i] == 'x' || s[i] == 'X' || s[i] == 'p' || s[i] == 'u')
		word = ft_unsignedworks(s, va_arg(args, unsigned long long));
	ft_putstr_fd(word, 1);
	i = ft_strlen(word);
	free(word);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (s == 0)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			size = size + ft_atow(&s[i], args) - 1;
			i++;
		}
		else
			ft_putchar_fd(s[i], 1);
		size++;
		i++;
	}
	va_end(args);
	return (size);
}
