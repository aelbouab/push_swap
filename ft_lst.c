/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:52:24 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/14 10:25:58 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*nede;

	nede = malloc(sizeof(t_list));
	if (!nede)
		return (NULL);
	nede->content = content;
	nede->next = nede;
	nede->prev = nede;
	nede->tf = 0;
	nede->cp = 1;
	nede->mv = 0;
	return (nede);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;
	bool	on;

	i = 0;
	on = 1;
	p = lst;
	while (p != lst || on)
	{
		p = p->next;
		i++;
		on = 0;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p->next != lst)
		p = p->next;
	return (p);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = ft_lstnew(new->content);
		return ;
	}
	(*lst)->prev = new;
	new->next = *lst;
	new->prev = ft_lstlast(*lst);
	ft_lstlast(*lst)->next = new;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*y;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	y = ft_lstlast(*lst);
	y->next = new;
	new->prev = y;
	new->next = *lst;
	(*lst)->prev = new;
}
