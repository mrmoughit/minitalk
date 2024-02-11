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
static void ft_desplay(void)
{
    ft_printf("\n");
    ft_printf("\033[1;33m");
    ft_printf("__________________________________   _________________________\n");
    ft_printf("/   _____/\\_   _____/\\______   \\   \\ /   /\\_   _____/\\______   \\\n");
    ft_printf("\\_____  \\  |    __)_  |       _/\\   Y   /  |    __)_  |       _/\n");
    ft_printf("/        \\ |        \\ |    |   \\ \\     /   |        \\ |    |   \\\n");
    ft_printf("/_______  //_______  / |____|_  /  \\___/   /_______  / |____|_  /\n");
    ft_printf("        \\/         \\/         \\/                   \\/         \\/\n");
    ft_printf("\033[0m");
	ft_printf("abechcha minitalk:)");
    ft_printf("\n");
	ft_printf("sever pid --------->");
}

void	ft_sig_handler(int sig, siginfo_t *v, void *n)
{
	static char  	i;
	static int	index;
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
		index = 0;
	}
	if (sig == SIGUSR1)
		i = i |(1 << index);
	else if (sig == SIGUSR2)
		i = i |(0 << index);
	index++;
	if (index == 8)
	{
		ft_printf("%c", i);
		i = 0;
		index = 0;
	}
}


int	main()
{
	ft_desplay();
	struct sigaction handler;
	ft_printf("%d\n", getpid());
    handler.sa_sigaction = ft_sig_handler;
   	handler.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &handler, NULL) == -1)
		ft_print_error("sigaction can't change behvior of signal");
	if (sigaction(SIGUSR2, &handler, NULL) == -1)
		ft_print_error("sigaction can't change behvior of signal");
	while (1)
		pause();
}