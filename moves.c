/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:18:08 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/16 10:06:32 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_list **stack_a, int p)
{
	t_list	*tmp;
	t_list	*tel;

	if (*stack_a && (*stack_a)->next)
	{
		tel = ft_lstlast(*stack_a);
		tmp = (*stack_a)->next->next;
		tmp->prev = *stack_a;
		tmp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = tel;
		tmp->next = (*stack_a)->next;
		(*stack_a)->next = tmp;
		tmp->prev = (*stack_a);
		tel->next = (*stack_a);
		if (p == 1)
			write (1, "sa\n", 3);
	}
}

void	sb(t_list **stack_b, int p)
{
	t_list	*tmp;
	t_list	*tel;

	if (*stack_b && (*stack_b)->next)
	{
		tel = ft_lstlast(*stack_b);
		tmp = (*stack_b)->next->next;
		tmp->prev = *stack_b;
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = tel;
		tmp->next = (*stack_b)->next;
		(*stack_b)->next = tmp;
		tmp->prev = (*stack_b);
		tel->next = (*stack_b);
		if (p == 1)
			write (1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b, int p)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (p == 1)
		write (1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*head_b;
	t_list	*tel_b;

	if (*stack_b)
	{
		head_b = *stack_b;
		tel_b = ft_lstlast(*stack_b);
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->content == head_b->content)
		{
			head_b = ft_lstnew((*stack_b)->content);
			ft_lstadd_front(stack_a, head_b);
			free (*stack_b);
			*stack_b = NULL;
			if (p == 1)
				write (1, "pa\n", 3);
			return ;
		}
		(*stack_b)->prev = tel_b;
		tel_b->next = *stack_b;
		ft_lstadd_front(stack_a, head_b);
		if (p == 1)
			write (1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int p)
{
	t_list	*head_a;
	t_list	*tel_a;

	if (*stack_a)
	{
		head_a = *stack_a;
		tel_a = ft_lstlast(*stack_a);
		*stack_a = (*stack_a)->next;
		if ((*stack_a)->content == head_a->content)
		{
			head_a = ft_lstnew((*stack_a)->content);
			ft_lstadd_front(stack_b, head_a);
			free (*stack_a);
			if (p == 1)
				write (1, "pb\n", 3);
			return ;
		}
		if (!(*stack_b))
			free (head_a);
		(*stack_a)->prev = tel_a;
		tel_a->next = *stack_a;
		ft_lstadd_front(stack_b, head_a);
		if (p == 1)
			write (1, "pb\n", 3);
	}
}
