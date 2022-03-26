/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:43:22 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/03/22 18:08:12 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//Structs
typedef struct s_stack
{
	struct s_node	*first;
	size_t			size;
	int				error;
}t_stack;
typedef struct s_node
{
	struct s_node	*next;
	int				num;
}t_node;

void	swap_a(t_stack *stack_a, int flag);
void 	swap_b(t_stack *stack_b, int flag);
void 	swap_ab(t_stack *stack_a, t_stack *stack_b);
void 	push_a(t_stack *stack_a, t_stack *stack_b);
void 	push_b(t_stack *stack_a, t_stack *stack_b);
t_stack	create_stack(int number);
void 	push(t_stack *stack, int number);
int		pop(t_stack *stack);
/*int		is_empty(t_stack *stack);
int		last_number(t_stack *stack);*/
void 	rotate_a(t_stack *stack_a, int flag);
void 	rotate_b(t_stack *stack_b, int flag);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a, int flag);
void	reverse_rotate_b(t_stack *stack_b, int flag);

//ATOI
int		ft_atoi(const char *str);

//SPLIT
size_t	len_string(size_t i, char const *s, char c);
char	**total_string(char const *s);
size_t	counter(char const *s, char c);
void	field(char **ptr, char const *s, char c);
char	**ft_split(char const *s, char c);

//STRLEN
size_t	ft_strlen(const char *s);

//STRLCPY
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//isDigit
int		ft_isdigit(char *str);

void	printeameesta(t_stack stack);
int		check_repeated_numbers(t_stack stack, int num);
int		sortlist(t_stack *stack_a, t_stack *stack_b);
int		check_error(int j, char **str, t_stack *stack, int *flag);
int		control_error(int j, char **str, t_stack *stack, int *flag);
int		push_numbers(int argc, char **argv, t_stack *stack);
void	free_entry(char **str);

//three number
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_hundred(t_stack *stack_a, t_stack *stack_b);
void	side(t_stack *stack, int *sorted);
int		*list_sorted(t_stack stack_a, int is_sorted);
void	sort_ascending(int *sorted, int size);
void	swap(int *xp, int *yp);
int		is_sort(t_stack stack_a);

void	free_nodes(t_stack stack);

#endif
 