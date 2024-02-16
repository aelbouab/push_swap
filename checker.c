/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:21:07 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/15 17:29:44 by aelbouab         ###   ########.fr       */
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

void	r_moves(t_list **stack_a, t_list **stack_b, char *move)
{
	if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
		ra(stack_a, 0);
	else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
		rb(stack_b, 0);
	else if (move[1] == 'r' && move[2] == '\n' && move[3] == '\0')
		rr(stack_a, stack_b, 0);
	else if (move[1] == 'r' && move[2] == 'a'
		&& move[3] == '\n' && move[4] == '\0')
		rra(stack_a, 0);
	else if (move[1] == 'r' && move[2] == 'b'
		&& move[3] == '\n' && move[4] == '\0')
		rrb(stack_b, 0);
	else if (move[1] == 'r' && move[2] == 'r'
		&& move[3] == '\n' && move[4] == '\0')
		rrr(stack_a, stack_b, 0);
	else
		return (write (2, "Error\n", 6), exit(1));
}

void	moves_p(t_list **stack_a, t_list **stack_b, int d, char *move)
{
	if (d == 1)
		r_moves(stack_a, stack_b, move);
	else if (d == 2)
	{
		if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
			sa(stack_a, 0);
		else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
			sb(stack_b, 0);
		else if (move[1] == 's' && move[2] == '\n' && move[3] == '\0')
			ss(stack_a, stack_b, 0);
		else
			return (write (2, "Error\n", 6), exit(1));
	}
	else if (d == 3)
	{
		if (move[1] == 'a' && move[2] == '\n' && move[3] == '\0')
			pa(stack_a, stack_b, 0);
		else if (move[1] == 'b' && move[2] == '\n' && move[3] == '\0')
			pb(stack_a, stack_b, 0);
		else
			return (write (2, "Error\n", 6), exit(1));
	}
}

void	filter(t_list **stack_a, t_list **stack_b, char *move)
{
	if (move[0] == 'r')
		moves_p(stack_a, stack_b, 1, move);
	else if (move[0] == 's')
		moves_p(stack_a, stack_b, 2, move);
	else if (move[0] == 'p')
		moves_p(stack_a, stack_b, 3, move);
	else
	{
		write (2, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*moves;

	stack_a = fillstack(ac, av);
	stack_b = NULL;
	while (1)
	{
		moves = get_next_line(0);
		if (!moves)
			break ;
		filter(&stack_a, &stack_b, moves);
		free (moves);
	}
	if (sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stackclear(&stack_a);
}
