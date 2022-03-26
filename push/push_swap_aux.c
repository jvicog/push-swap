/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:50:10 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/03/22 18:08:14 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	create_stack(int number)
{
	t_node	*first_node;
	t_stack	stack;

	stack.first = NULL;
	stack.size = 1;
	stack.error = 0;
	first_node = malloc(sizeof(t_node));
	if (first_node == NULL)
		return (stack);
	first_node->num = number;
	first_node->next = NULL;
	stack.first = first_node;
	return (stack);
}

void	push(t_stack *stack, int number)
{
	t_node	*next_node;

	next_node = malloc(sizeof(t_node));
	if (next_node == NULL)
		return ;
	next_node->next = stack->first;
	next_node->num = number;
	stack->first = next_node;
	stack->size += 1;
}

void	swap_a(t_stack *stack_a, int flag)
{
	t_node	*second_node;

	if (stack_a->size <= 1)
		return ;
	second_node = stack_a->first->next;
	stack_a->first->next = stack_a->first->next->next;
	second_node->next = stack_a->first;
	stack_a->first = second_node;
	if (flag)
		write(1, "sa\n", 3);
}

int	pop(t_stack *stack)
{
	int		pop_number;
	t_node	*pop_node;

	pop_number = stack->first->num;
	pop_node = stack->first;
	stack->size -= 1;
	if (stack->size == 0)
		stack->first = NULL;
	else
		stack->first = stack->first->next;
	free(pop_node);
	return (pop_number);
}

/*int is_empty(t_stack *stack)
{
	if(stack->size == 0)
		return (1);
	return (0);
}

int last_number(t_stack *stack)
{
	t_node  *node;

	node = stack->first;
	while (node->next != NULL)
		node = node->next;
	return(node->num);
}*/

void	swap_b(t_stack *stack_b, int flag)
{
	t_node	*second_node;

	if (stack_b->size <= 1)
		return ;
	second_node = stack_b->first->next;
	stack_b->first->next = second_node->next;
	second_node->next = stack_b->first;
	stack_b->first = second_node;
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(1, "ss\n", 3);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_aux;

	if (stack_b->size <= 0)
		return ;
	node_aux = stack_b->first;
	stack_b->first = node_aux->next;
	node_aux->next = stack_a->first;
	stack_a->first = node_aux;
	stack_b->size = stack_b->size - 1;
	stack_a->size = stack_a->size + 1;
	write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_aux;

	if (stack_a->size <= 0)
		return ;
	node_aux = stack_a->first;
	stack_a->first = node_aux->next;
	node_aux->next = stack_b->first;
	stack_b->first = node_aux;
	stack_a->size = stack_a->size - 1;
	stack_b->size = stack_b->size + 1;
	write(1, "pb\n", 3);
}

void	rotate_a(t_stack *stack_a, int flag)
{
	t_node	*node_aux;

	node_aux = stack_a->first;
	while (node_aux->next != NULL)
		node_aux = node_aux->next;
	node_aux->next = stack_a->first;
	stack_a->first = stack_a->first->next;
	node_aux->next->next = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, int flag)
{
	t_node	*node_aux;

	node_aux = stack_b->first;
	while (node_aux->next != NULL)
		node_aux = node_aux->next;
	node_aux->next = stack_b->first;
	stack_b->first = stack_b->first->next;
	node_aux->next->next = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack *stack_a, int flag)
{
	t_node	*node_aux;

	node_aux = stack_a->first;
	while (node_aux->next->next != NULL)
		node_aux = node_aux->next;
	node_aux->next->next = stack_a->first;
	stack_a->first = node_aux->next;
	node_aux->next = NULL;
	if (flag)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack_b, int flag)
{
	t_node	*node_aux;

	node_aux = stack_b->first;
	while (node_aux->next->next != NULL)
		node_aux = node_aux->next;
	node_aux->next->next = stack_b->first;
	stack_b->first = node_aux->next;
	node_aux->next = NULL;
	if (flag)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	write(1, "rrr\n", 4);
}
