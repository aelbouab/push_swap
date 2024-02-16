/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:51:57 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/16 10:01:53 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(t_list *stack_a)
{
	int	ls;
	int	i;

	ls = ft_lstsize(stack_a);
	i = 0;
	while (i < ls - 1)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

t_list	*fillstack(int ac, char **av)
{
	int		i;
	int		len;
	int		*a;
	t_list	*stack_a;
	t_list	*new_a;

	i = 0;
	len = spacelloc(ac, av, 1, 0);
	a = parssing(ac, av);
	if (a == NULL)
		exit (0);
	stack_a = ft_lstnew(a[i]);
	i++;
	while (i < len)
	{
		new_a = ft_lstnew(a[i]);
		ft_lstadd_back(&stack_a, new_a);
		i++;
	}
	free (a);
	return (stack_a);
}

void	countlonglist(t_list **stack_a, int ls, int i, int j)
{
	t_list	*head;
	t_list	*head2;
	int		count;

	head = *stack_a;
	while (++i < ls)
	{
		count = 1;
		head2 = head;
		j = 0;
		while (j < ls)
		{
			if (head->content < head2->next->content)
			{
				count++;
				head = head2->next;
			}
			head2 = head2->next;
			j++;
		}
		(*stack_a)->tf = 1;
		(*stack_a)->cp = count;
		*stack_a = (*stack_a)->next;
		head = *stack_a;
	}
}

t_list	*largf(t_list *stack_a, int ls)
{
	t_list	*larg;
	t_list	*new1;
	int		i;

	i = 0;
	larg = stack_a;
	new1 = stack_a;
	while (i < ls)
	{
		if (new1->cp < stack_a->next->cp)
		{
			larg = stack_a->next;
			new1 = stack_a->next;
		}
		stack_a = stack_a->next;
		i++;
	}
	return (larg);
}

t_list	*longlist(t_list *stack_a)
{
	t_list	*larg;
	t_list	*new1;
	t_list	*new2;
	int		ls;
	int		i;

	i = 0;
	ls = ft_lstsize(stack_a);
	countlonglist(&stack_a, ft_lstsize(stack_a), -1, 0);
	larg = largf(stack_a, ls);
	new1 = larg;
	new2 = larg;
	new1->tf = 0;
	while (i < ls)
	{
		if (new2->content < new1->content)
		{
			new1->tf = 0;
			new2 = new1;
		}
		new1 = new1->next;
		i++;
	}
	return (larg);
}
