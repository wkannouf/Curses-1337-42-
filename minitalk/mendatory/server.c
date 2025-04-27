/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 23:45:50 by wkannouf          #+#    #+#             */
/*   Updated: 2025/03/11 00:32:22 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static int	g_pid_c;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	count_bit;

	(void)context;
	if (info->si_pid != g_pid_c)
	{
		g_pid_c = info->si_pid;
		c = 0;
		count_bit = 0;
	}
	if (sig == SIGUSR2)
		c = c | (1 << (7 - count_bit));
	count_bit++;
	if (count_bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		count_bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	g_pid_c = -1;
	signal.sa_flags = SA_SIGINFO;
	signal.sa_sigaction = handle_signal;
	if (sigaction(SIGUSR1, &signal, NULL) == -1 \
		|| sigaction(SIGUSR2, &signal, NULL) == -1)
		return (1);
	while (1)
		;
	return (0);
}
