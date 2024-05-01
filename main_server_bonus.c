/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:52:55 by mnie              #+#    #+#             */
/*   Updated: 2024/02/18 13:43:57 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_error(char *message)
{
	ft_putstr_fd("error\n", 1);
	if (message)
	{
		free(message);
		message = NULL;
	}
	exit(1);
}

void	print_pid(int s_pid)
{
	char	*pid;

	pid = ft_itoa(s_pid);
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	free(pid);
}

char	*print_message(char *message)
{
	if (message)
	{
		ft_putstr_fd(message, 1);
		ft_putchar_fd('\n', 1);
		free(message);
		return (NULL);
	}
	return (NULL);
}

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static char	*message;
	static char	c;
	static int	bits;

	(void)context;
	if (signum == SIGUSR1)
		c = clear_bit(c, bits);
	else
		c = set_bit(c, bits);
	bits++;
	if (bits == 8)
	{
		if (c == 0)
		{
			message = print_message(message);
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_error(message);
		}
		else
			message = add_char_to_str(message, c);
		bits = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_error(message);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			mask;

	sigemptyset(&mask);
	sa.sa_handler = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = mask;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid(getpid());
	while (1)
		pause();
	return (0);
}
