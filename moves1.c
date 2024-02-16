/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:19:36 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/13 10:25:10 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_list **stack_a, int p)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		if (p == 1)
			write (1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b, int p)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		if (p == 1)
			write (1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int p)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (p == 1)
		write (1, "rr\n", 3);
}

void	rra(t_list **stack_a, int p)
{
	t_list	*tel;

	if ((*stack_a) && (*stack_a)->next)
	{
		tel = ft_lstlast(*stack_a);
		*stack_a = tel;
		if (p == 1)
			write (1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int p)
{
	t_list	*tel;

	if ((*stack_b) && (*stack_b)->next)
	{
		tel = ft_lstlast(*stack_b);
		*stack_b = tel;
		if (p == 1)
			write (1, "rrb\n", 4);
	}
}
