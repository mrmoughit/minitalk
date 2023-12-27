/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:47:52 by abechcha          #+#    #+#             */
/*   Updated: 2023/12/27 11:37:46 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "minitalk.h"

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
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i++;
		bits++;
		//usleep(1000);
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
