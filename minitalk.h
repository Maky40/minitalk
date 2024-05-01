/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:50:53 by mnie              #+#    #+#             */
/*   Updated: 2024/02/18 14:07:19 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/include/libft.h"

int		clear_bit(int c, int position);
int		set_bit(int c, int position);
char	*add_char_to_str(char *message, char c);

#endif
