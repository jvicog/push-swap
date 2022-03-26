/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:49:07 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/03/22 19:13:27 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	*sorted;

	sorted = list_sorted(*stack_a, 0);
	if (sorted[0] > sorted[1] && sorted[0] < sorted[2])
		swap_a(stack_a, 1);
	else if (sorted[0] > sorted[1] && sorted[1] > sorted[2])
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}
	else if (sorted[0] > sorted[1] && sorted[1] < sorted[2])
		rotate_a(stack_a, 1);
	else if (sorted[0] < sorted[1] && sorted[2] > sorted[0])
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else
		reverse_rotate_a(stack_a, 1);
	free(sorted);
	sorted = NULL;
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;
	int	i;

	i = stack_a->size;
	sorted = list_sorted(*stack_a, 1);
	while (stack_a->size > 3)
	{
		if (stack_a->first->num == sorted[0]
			|| (stack_a->first->num == sorted[1] && i == 5))
			push_b(stack_a, stack_b);
		else if (stack_a->size > 3)
			rotate_a(stack_a, 1);
	}
	if (!is_sort(*stack_a))
		sort_three(stack_a);
	if (is_sort(*stack_b))
		swap_b(stack_b, 1);
	printeameesta(*stack_a);
	while (stack_b->size != 0)
		push_a(stack_a, stack_b);
	free(sorted);
	sorted = NULL;
}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;
	int	mid;

	/////////////////////////
	// LLEVAR A B
	////////////////////////
	while (stack_a->size > 5 && !is_sort(*stack_a))
	{
		sorted = list_sorted(*stack_a, 1);
		mid = stack_a->size / 2;
		printf("%d", mid);
		while (stack_a->size > mid && !is_sort(*stack_a))
		{
			if (stack_a->first->num <= sorted[mid])
				push_b(stack_a, stack_b);
			else
				side(stack_a, sorted);
		}
		free(sorted);
	}
	printf("A ES ESTA\n");
	printeameesta(*stack_a);
	printf("B ES ESTA\n");
	printeameesta(*stack_b);
}
//void	mid_to_b(t_stack *stack_a, t_stack_)

void	side(t_stack *stack, int *sorted)
{
	t_node	*node;
	int		min;
	int		max;
	int		lock;
	int		i;

	node = stack->first;
	lock = 0;
	i = 0;
	while (node != NULL)
	{
		if (node->num <= sorted[stack->size / 2] && !lock)
		{
			min = i;
			lock = 1;
		}
		else if (node->num <= sorted[stack->size / 2])
			max = i;
		i++;
		node = node->next;
	}
	if (min < (stack->size - max))
		rotate_a(stack, 1);
	else
		reverse_rotate_a(stack, 1);
}

int	*list_sorted(t_stack stack_a, int is_sorted)
{
	t_node	*node;
	int		i;
	int		*sorted;

	i = 0;
	node = stack_a.first;
	sorted = malloc(sizeof(int) * stack_a.size);
	while (node != NULL)
	{
		sorted[i] = node->num;
		node = node->next;
		i++;
	}
	if (is_sorted)
		sort_ascending(sorted, stack_a.size);
	return (sorted);
}

void	sort_ascending(int *sorted, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (sorted[j] < sorted[min])
				min = j;
			j++;
		}
		swap(&sorted[min], &sorted[i]);
		i++;
	}
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
