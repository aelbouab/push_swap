/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:53:47 by aelbouab          #+#    #+#             */
/*   Updated: 2024/02/16 11:05:36 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		main(int ac, char **av);
char	**ft_split(char const *s, char c);
void	testdigit(int ac, char **av);
int		spacelloc(int ac, char **av, int i, int x);
void	freearray(char **cav, char *sav);
int		*parssing(int ac, char **av);

typedef struct s_list
{
	int				content;
	bool			tf;
	int				cp;
	int				mv;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list	*fillstack(int ac, char **av);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	sa(t_list **stack_a, int p);
void	sb(t_list **stack_b, int p);
void	ss(t_list **stack_a, t_list **stack_b, int p);
void	pa(t_list **stack_a, t_list **stack_b, int p);
void	pb(t_list **stack_a, t_list **stack_b, int p);
void	ra(t_list **stack_a, int p);
void	rb(t_list **stack_b, int p);
void	rr(t_list **stack_a, t_list **stack_b, int p);
void	rra(t_list **stack_a, int p);
void	rrb(t_list **stack_b, int p);
void	rrr(t_list **stack_a, t_list **stack_b, int p);
void	fillmove(t_list *stack_a, t_list *stack_b, int ls);
void	bestmove1(t_list *stack_a, t_list *stack_b, int ls, int i);
void	bestmove(t_list *stack_a, t_list *stack_b);
void	besthead(t_list **stack_b, int ls);
int		sorted(t_list *stack_a);
void	stack_index(t_list *stack_a, t_list *stack_b);
void	countlonglist(t_list **stack_a, int ls, int i, int j);
t_list	*longlist(t_list *stack_a);
t_list	*sort_list(t_list *stack_a, t_list *stack_b, t_list	*head);
void	changehead(t_list **stack_a, t_list **stack_b, t_list *new);
t_list	*maxandmin(t_list **stack_a, int ls, int on);
void	sorta(t_list **stack_a, t_list **stack_b);
void	push_toa(t_list **stack_a, t_list **stack_b);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_serch(const char *s, int c);
char	*ft_strdup(char *src);
size_t	ft_len(const char *str, int j);
char	*ft_join(char *s1, char *s2);
int		main(int ac, char **av);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif