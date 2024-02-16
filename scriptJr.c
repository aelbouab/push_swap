/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scriptJr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:21:32 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/15 17:26:35 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	testdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9' && (av[i][j + 1] == '-'
				|| av[i][j + 1] == '+'))
				return (write (2, "Error\n", 6), exit (1));
			if ((av[i][j] == '-' || av[i][j] == '+')
				&& !(av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
				return (write (2, "Error\n", 6), exit (1));
			if ((av[i][j] < '0' || av[i][j] > '9')
				&& av[i][j] != '-' && av[i][j] != '+'
				&& (av[i][j] < 9 || av[i][j] > 13) && av[i][j] != 32)
				return (write (2, "Error\n", 6), exit (1));
			j++;
		}
		i++;
	}
}

int	spacelloc(int ac, char **av, int i, int x)
{
	int	j;
	int	n;

	while (i < ac)
	{
		j = 0;
		n = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-'
				|| av[i][j] == '+')
				x++;
			else
				n++;
			while ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '-'
					|| av[i][j] == '+')
				j++;
			if (av[i][j])
				j++;
		}
		if (n == (int)ft_strlen(av[i]))
			return (write (2, "Error\n", 6), exit(1), 0);
		i++;
	}
	return (x);
}

void	freearray(char **cav, char *sav)
{
	int	i;

	i = 0;
	while (cav[i])
	{
		free (cav[i]);
		i++;
	}
	free (cav);
	cav = NULL;
	free(sav);
}
