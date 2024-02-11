/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abechcha <abechcha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:10:58 by abechcha          #+#    #+#             */
/*   Updated: 2023/12/26 18:08:28 by abechcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_atoi(const char *str);
void ft_print_error(char *s);
int ft_strlen(char *s);

#endif
