/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:51:04 by mnie              #+#    #+#             */
/*   Updated: 2024/02/18 13:43:55 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	clear_bit(int c, int position)
{
	return (c & ~(1 << position));
}

int	set_bit(int c, int position)
{
	return (c | (1 << position));
}

char	*add_char_to_str(char *message, char c)
{
	char	*ret;
	size_t	size;
	int		i;

	if (!message)
	{
		ret = malloc(sizeof(char) * 2);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	size = ft_strlen(message) + 2;
	ret = malloc(sizeof(char) * size);
	i = 0;
	while (message[i])
	{
		ret[i] = message[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	free(message);
	return (ret);
}
