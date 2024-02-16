/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestmove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:23:23 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/13 10:21:45 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_list **stack_a, t_list **stack_b, int p)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (p == 1)
		write (1, "rrr\n", 4);
}

void	fillmove(t_list *stack_a, t_list *stack_b, int ls)
{
	int	i;

	i = -1;
	while (++i < ls)
	{
		if (stack_a->cp <= (ls / 2) + 1)
			stack_a->mv = stack_a->cp - 1;
		else
			stack_a->mv = ls - (stack_a->cp - 1);
		stack_a = stack_a->next;
	}
	if (stack_b)
	{
		ls = ft_lstsize(stack_b);
		i = -1;
		while (++i < ls)
		{
			if (stack_b->cp <= (ls / 2) + 1)
				stack_b->mv = stack_b->cp - 1;
			else
				stack_b->mv = ls - (stack_b->cp - 1);
			stack_b = stack_b->next;
		}
	}
}

void	bestmove1(t_list *stack_a, t_list *stack_b, int ls, int i)
{
	t_list	*tmp;
	bool	on;

	on = 1;
	while (++i < ls)
	{
		if (stack_a->content < stack_b->content
			&& stack_b->content < stack_a->next->content)
		{
			stack_b->mv += stack_a->next->mv;
			on = 0;
		}
		stack_a = stack_a->next;
	}
	if (on == 1)
	{
		i = -1;
		while (++i < ls)
		{
			if (stack_a->content > stack_a->next->content)
				tmp = stack_a->next;
			stack_a = stack_a->next;
		}
		stack_b->mv += tmp->mv;
	}
}

void	bestmove(t_list *stack_a, t_list *stack_b)
{
	int		ls;
	int		lsa;
	int		i;

	i = 0;
	fillmove(stack_a, stack_b, ft_lstsize(stack_a));
	ls = ft_lstsize(stack_b);
	lsa = ft_lstsize(stack_a);
	while (i < ls)
	{
		bestmove1(stack_a, stack_b, lsa, -1);
		stack_b = stack_b->next;
		i++;
	}
}

void	besthead(t_list **stack_b, int ls)
{
	t_list	*new;
	t_list	*best_h;
	int		i;

	new = *stack_b;
	best_h = *stack_b;
	i = -1;
	while (++i < ls)
	{
		if (best_h->mv > new->next->mv)
		{
			best_h = new->next;
		}
		new = new->next;
	}
	if (best_h->cp <= (ls / 2) + 1)
	{
		while (*stack_b != best_h)
			rb(stack_b, 1);
	}
	else
	{
		while (*stack_b != best_h)
			rrb(stack_b, 1);
	}
}
