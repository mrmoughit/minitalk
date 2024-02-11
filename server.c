/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:47:28 by abechcha          #+#    #+#             */
/*   Updated: 2024/02/04 17:22:09 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sig_handler(int sig, siginfo_t *v, void *n)
{
	static char  	i;
	static int	bits;
	static int c_pid;
	static int db;

	(void)n;
	if (!c_pid)
		c_pid = v->si_pid;
	db = v->si_pid;
	if (c_pid != db)
	{
		c_pid = v->si_pid;
		i = 0;
		bits = 0;
	}
	if (sig == SIGUSR1)
		i |= (1 << bits);
	else if (sig == SIGUSR2)
		i |= (0 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bits = 0;
	}
}


int	main()
{
	struct sigaction sa;
	ft_printf("%d\n", getpid());
    sa.sa_sigaction = ft_sig_handler;
   	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_print_error("sigaction can't change behvior of signal");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_print_error("sigaction can't change behvior of signal");
	while (1)
		pause();
}