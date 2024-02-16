/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:24:55 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/14 10:55:25 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*sort_list(t_list *stack_a, t_list *stack_b, t_list	*head)
{
	int		i;
	int		ls;
	bool	on;

	i = -1;
	on = 1;
	head = stack_a;
	if (stack_b)
	{
		ls = ft_lstsize(stack_a);
		while (++i < ls)
		{
			if (stack_a->content < stack_b->content
				&& stack_b->content < stack_a->next->content)
			{
				head = stack_a->next;
				on = 0;
				break ;
			}
			stack_a = stack_a->next;
		}
		if (on == 0)
			return (head);
	}
	return (head->tf = 1, head);
}

void	changehead(t_list **stack_a, t_list **stack_b, t_list *new)
{
	int	ls;

	ls = ft_lstsize(*stack_a);
	if (new->cp <= (ls / 2) + 1)
	{
		while (*stack_a != new)
			ra(stack_a, 1);
	}
	else
	{
		while (*stack_a != new)
			rra(stack_a, 1);
	}
	pa(stack_a, stack_b, 1);
	(*stack_a)->tf = 0;
	stack_index (*stack_a, *stack_b);
}

t_list	*maxandmin(t_list **stack_a, int ls, int on)
{
	t_list	*mm;
	int		i;

	i = 0;
	mm = *stack_a;
	while (i < ls && on == 1)
	{
		if (mm->content < (*stack_a)->content)
			mm = *stack_a;
		*stack_a = (*stack_a)->next;
		i++;
	}
	while (i < ls && on == 0)
	{
		if (mm->content > (*stack_a)->content)
			mm = *stack_a;
		*stack_a = (*stack_a)->next;
		i++;
	}
	return (mm);
}

void	sorta(t_list **stack_a, t_list **stack_b)
{
	int		ls;
	int		i;
	t_list	*low;

	low = maxandmin(stack_a, ft_lstsize(*stack_a), 0);
	i = 0;
	ls = ft_lstsize(*stack_a);
	if (low->cp <= (ls / 2) + 1)
	{
		while (*stack_a != low)
			ra(stack_a, 1);
	}
	else
	{
		while (*stack_a != low)
			rra(stack_a, 1);
	}
	if (*stack_b)
	{
		pa(stack_a, stack_b, 1);
		(*stack_a)->tf = 0;
	}
	stack_index (*stack_a, *stack_b);
}

void	push_toa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	head = NULL;
	while (*stack_b)
	{
		bestmove (*stack_a, *stack_b);
		besthead (stack_b, ft_lstsize(*stack_b));
		stack_index (*stack_a, *stack_b);
		head = sort_list (*stack_a, *stack_b, head);
		if (head->tf == 1)
		{
			head->tf = 0;
			sorta(stack_a, stack_b);
		}
		else
			changehead(stack_a, stack_b, head);
	}
	sorta(stack_a, stack_b);
}
