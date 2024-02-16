/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:57:01 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/15 17:26:39 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static char	*rmspace1(char *av, char *sav, int i, int j)
{
	int		l;
	int		cp;

	l = 0;
	cp = 0;
	while (av[i])
	{
		if (!((av[i] >= 9 && av[i] <= 13) || av[i] == 32))
			j++;
		while (!((av[i] >= 9 && av[i] <= 13) || av[i] == 32) && av[i])
		{
			l++;
			i++;
		}
		if (av[i])
			i++;
	}
	cp = l + j;
	sav = malloc(cp + 1);
	if (!sav)
		return (NULL);
	return (sav);
}

static char	*rmspace(char *av)
{
	char	*sav;
	int		i;
	int		j;

	sav = NULL;
	sav = rmspace1(av, sav, 0, 0);
	i = 0;
	j = 0;
	while (av[i])
	{
		while (!((av[i] >= 9 && av[i] <= 13) || av[i] == 32) && av[i])
		{
			sav[j] = av[i];
			j++;
			i++;
			if (((av[i] >= 9 && av[i] <= 13) || av[i] == 32) || av[i] == '\0')
				sav[j++] = ' ';
		}
		if (av[i])
			i++;
	}
	sav[j] = '\0';
	return (sav);
}

static int	*testnsplite(char **av, int *a, int i, int x)
{
	char	**cav;
	char	*sav;
	int		r;
	int		j;

	a = malloc(sizeof(int) * x);
	if (!a)
		return (0);
	x = -1;
	while (av[++i])
	{
		j = -1;
		sav = rmspace(av[i]);
		cav = ft_split(sav, ' ');
		while (cav[++j])
		{
			a[++x] = ft_atoi(cav[j]);
			r = -1;
			while (++r < x)
				if (a[r] == a[x])
					return (write (2, "Error\n", 6), exit(1), NULL);
		}
		freearray(cav, sav);
	}
	return (a);
}

int	*parssing(int ac, char **av)
{
	int	i;
	int	x;
	int	*a;

	a = NULL;
	i = 0;
	if (ac > 1)
	{
		testdigit(ac, av);
		x = spacelloc(ac, av, 1, 0);
		a = testnsplite(av, a, 0, x);
	}
	return (a);
}
