/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:47:52 by abechcha          #+#    #+#             */
/*   Updated: 2023/12/27 13:02:58 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
void	ft_sighandler(int pid, char c)
{
	int	i;
	int	bits;

	i = 0;
	bits = 0;
	while (bits < 8)
	{
		if ((c & (1 << i)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_print_error("pid not Valid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_print_error("pid not Valid\n");
		}
		i++;
		bits++;
		usleep(450);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1 || pid == 0)
		{
			ft_print_error("pid error\n");
			exit(0);
		}
		if (av[2][0] == '\0')
			ft_print_error("empty string");
		while (av[2][i])
		{
			ft_sighandler(pid, av[2][i]);
			i++;
		}
		ft_sighandler(pid, '\0');
	}
	else
		return (ft_printf("the client program take a 3 param"), 1);
	return (0);
}
