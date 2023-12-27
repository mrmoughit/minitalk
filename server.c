/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:47:28 by abechcha          #+#    #+#             */
/*   Updated: 2023/12/27 11:04:24 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sig_handler(int sig)
{
	static int	i;
	static int	bits;

	if (sig == SIGUSR1)
		i |= (1 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bits = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		return (ft_printf("error , the program take one param"), 1);
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, ft_sig_handler);
		signal(SIGUSR1, ft_sig_handler);
		pause();
	}
}
