/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 00:08:40 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/27 06:19:51 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <signal.h>

void	success(int sig)
{
	(void)sig;
	write(1, "Message Received\n", 17);
}

static short	overflow(size_t result, size_t b_result)
{
	if ((result / 10 != b_result) || (result >= LONG_MAX))
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		result;
	int		b_result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		b_result = result;
		result = result * 10 + str[i++] - 48;
		if (overflow(result, b_result) == 0)
			return (0);
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i])
		return (0);
	return (result);
}

static void	send_bit(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (((c >> (7 - bit)) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
		return (write(2, "argv != 3\n", 10), 1);
	if (kill(pid, 0) == -1 || pid <= 0)
		return (write(2, "Invalid PID.\n", 13), 1);
	signal(SIGUSR1, success);
	while (argv[2][i])
	{
		send_bit(pid, argv[2][i]);
		i++;
	}
	send_bit(pid, '\n');
	send_bit(pid, '\0');
	return (0);
}
