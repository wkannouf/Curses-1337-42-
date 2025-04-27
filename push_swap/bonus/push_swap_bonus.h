/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 20:50:45 by wkannouf          #+#    #+#             */
/*   Updated: 2025/04/15 07:04:10 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <libc.h>

typedef struct s_node
{
	int				n;
	struct s_node	*next;
}	t_stack;

void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	ft_lstclear(t_stack **lst);
void	ft_lstdelone(t_stack **lst);
t_stack	*ft_lstnew(int n);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	pa(t_stack **stack_a, t_stack **stack_b);
char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd, char **numbers, t_stack **stack_a);
ssize_t	ft_atoi(const char *str);
void	free_split(char **numbers);
void	full_stack_a(t_stack **stack_a, int argc, char **argv);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *line, const char *buffer);
char	*ft_strchr(char *line, int c);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack_a, t_stack **stack_b, int c);
void	rb(t_stack **stack_b);
void	rrb(t_stack **stack_b);
t_stack	*ft_lstlast(t_stack *lst);
char	**take_ops(char *op, char *ops, t_stack **stack_a);
int		is_sorted(t_stack *stack_a);

#endif
