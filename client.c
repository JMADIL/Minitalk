/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:17:46 by ajamoun           #+#    #+#             */
/*   Updated: 2025/01/19 21:15:49 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_pid(char *str)
{
	int	pid;
	int	i;

	pid = ft_atoi(str);
	if (pid < 0)
		return (0);
	i = kill(pid, 0);
	if (i = -1)
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

	i = 0;
	if (ac == 3)
	{
		if (check_pid(argv[1]))
		{
			while (av[2][i] != '\0')
			{
				send_bits(argv[1], av[2][i]);
				i++;
			}
			ft_putchar('\n');
		}
		else
			ft_putstr("The provided PID is invalid. Please check and try again!\n");
	}
	else
		ft_putstr("Syntax error! \n");
	return (0);
}