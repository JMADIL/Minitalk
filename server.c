/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:15:12 by ajamoun           #+#    #+#             */
/*   Updated: 2025/01/20 20:49:53 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_server(void)
{
	ft_putstr("\033[1;34m");
	ft_putstr(" ███████ ███████ ██████  ██    ██ ███████ ██████  \n");
    ft_putstr(" ██      ██      ██   ██ ██    ██ ██      ██   ██ \n");
    ft_putstr(" ███████ █████   ██████  ██    ██ █████   ██████  \n");
    ft_putstr("      ██ ██      ██   ██  ██  ██  ██      ██   ██ \n");
    ft_putstr(" ███████ ███████ ██   ██   ████   ███████ ██   ██ \n");
	ft_putstr("\033[0m");
	ft_putchar('\n');
}
void signal_handler(int signum)
{
	static int bit_count;
	static char our_char;
	static pid_t our_client_pid;
		
		if (signum == SIGUSR1)
			our_char = our_char << 1 | 0;
		else
			our_char = our_char << 1 | 1;
		bit_count++;
		if (bit_count == 8)
		{
			ft_putchar(our_char);
			bit_count = 0;
			our_char = 0;
		}
}
int main(void)
{	
	print_server();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_putstr("Hahuwa pid : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	while(1)
	{
		pause();
	}
}