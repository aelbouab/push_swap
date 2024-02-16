/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:32:59 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/16 10:44:45 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	stackclear(t_list **stack)
{
	t_list	*head;
	t_list	*tell;
	int		i;
	int		ls;

	tell = ft_lstlast(*stack);
	ls = ft_lstsize(*stack);
	i = 0;
	while (i < ls)
	{
		if (ft_lstsize(*stack) == 1)
		{
			free(*stack);
			*stack = NULL;
			break ;
		}
		head = *stack;
		*stack = (*stack)->next;
		tell->next = *stack;
		free (head);
		head = NULL;
		i++;
	}
}

void	stack_index(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;

	j = 0;
	i = ft_lstsize(stack_a);
	while (j < i)
	{
		stack_a->cp = j + 1;
		stack_a = stack_a->next;
		j++;
	}
	if (stack_b)
	{
		j = 0;
		i = ft_lstsize(stack_b);
		while (j < i)
		{
			stack_b->cp = j + 1;
			stack_b = stack_b->next;
			j++;
		}
	}
}

void	fake(t_list **stack_a, t_list **stack_b, int avg)
{
	t_list	*new_a;
	int		larg;

	larg = longlist(*stack_a)->cp;
	while (larg != ft_lstsize(*stack_a))
	{
		sa(stack_a, 0);
		new_a = longlist(*stack_a);
		if (new_a->cp > larg)
		{
			larg = new_a->cp;
			write(1, "sa\n", 3);
			continue ;
		}
		sa(stack_a, 0);
		longlist(*stack_a);
		if ((*stack_a)->tf == 1)
		{
			pb(stack_a, stack_b, 1);
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->content > avg)
				rb(stack_b, 1);
		}
		else
			ra(stack_a, 1);
	}
}

int	main(int ac, char **av)
{
	int		max;
	int		min;
	int		avg;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = fillstack(ac, av);
	stack_b = NULL;
	if (!sorted(stack_a))
	{
		max = maxandmin(&stack_a, ft_lstsize(stack_a), 1)->content;
		min = maxandmin(&stack_a, ft_lstsize(stack_a), 0)->content;
		avg = (max / 2) + (min / 2);
		fake (&stack_a, &stack_b, avg);
		stack_index (stack_a, stack_b);
		push_toa(&stack_a, &stack_b);
	}
	stackclear(&stack_a);
}
