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
void ft_diplay(void)
{
    ft_printf("\n");
	ft_printf("\033[1;34m");
    ft_printf("                                                              \n");
    ft_printf("            ,--,                                     ___     \n");
    ft_printf("          ,--.'|     ,--,                          ,--.'|_   \n");
    ft_printf("          |  | :   ,--.'|                  ,---,   |  | :,'  \n");
    ft_printf("          :  : '   |  |,               ,-+-. /  |  :  : ' :  \n");
    ft_printf("   ,---.  |  ' |   `--'_       ,---.  ,--.'|'   |.;__,'  /   \n");
    ft_printf("  /     \\ '  | |   ,' ,'|     /     \\|   |  ,\"' ||  |   |    \n");
    ft_printf(" /    / ' |  | :   '  | |    /    /  |   | /  | |:__,'| :    \n");
    ft_printf(".    ' /  '  : |__ |  | :   .    ' / |   | |  | |  '  : |__  \n");
    ft_printf("'   ; :__ |  | '.'|'  : |__ '   ;   /|   | |  |/   |  | '.'| \n");
    ft_printf("'   | '.'|;  :    ;|  | '.'|'   |  / |   | |--'    ;  :    ; \n");
    ft_printf("|   :    :|  ,   / ;  :    ;|   :    |   |/        |  ,   /  \n");
    ft_printf("\\   \\  /  ---`-'  |  ,   /  \\   \\  /'---'          ---`-'   \n");
    ft_printf(" `----'            ---`-'    `----'                          \n");
    ft_printf("                                                              \n");
	ft_printf("\033[0m");
}

void	ft_sighandler(int pid, char c)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (index < 8)
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
		index++;
		usleep(800);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid_server;

	i = 0;
	if (ac == 3)
	{
		ft_diplay();
		pid_server = ft_atoi(av[1]);
		if (pid_server == -1 || pid_server == 0)
		{
			ft_print_error("pid error\n");
		}
		if (av[2][0] == '\0')
			ft_print_error("empty string");
		while (av[2][i])
		{
			ft_sighandler(pid_server, av[2][i]);
			i++;
		}
	}
	else
		return (ft_printf("the client program take a 3 param"), 1);
	return (0);
}
