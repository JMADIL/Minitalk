/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:17:46 by ajamoun           #+#    #+#             */
/*   Updated: 2025/01/20 19:26:05 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    print_success()
{
    ft_putstr("\033[1;32m");
    
    ft_putstr(" ███████ ██    ██  ██████  ██████ ███████ ███████ ███████\n");
    ft_putstr(" ██      ██    ██ ██      ██      ██      ██      ██     \n");
    ft_putstr(" ███████ ██    ██ ██      ██      █████   ███████ ███████\n");
    ft_putstr("      ██ ██    ██ ██      ██      ██           ██      ██\n");
    ft_putstr(" ███████  ██████   ██████  ██████ ███████ ███████ ███████\n");
    
    ft_putstr("\033[0m");
}
int	check_pid(char *str)
{
	int	pid;
	int	i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i == -1)
		return (0);
	return (pid);
}
void	send_bits(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
}
int	main(int ac, char **av)
{
	int i;
	int pid;

	i = 0;
	if (ac == 3)
	{
		if (check_pid(av[1]))
		{
			pid = ft_atoi(av[1]);
			while (av[2][i] != '\0')
			{
				send_bits(pid, av[2][i]);
				i++;
			}
			ft_putchar('\n');
			print_success();
		}
		else
			ft_putstr("The provided PID is invalid. Please check and try again!\n");
	}
	else
		ft_putstr("Syntax error! \n");
	return (0);
}