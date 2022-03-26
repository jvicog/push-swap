/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvico-ga <jvico-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:02 by jvico-ga          #+#    #+#             */
/*   Updated: 2022/03/22 18:23:34 by jvico-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_stack	stack_b;

	stack_b = create_stack(0);
	pop(&stack_b);
	if (!push_numbers(argc, argv, &stack))
	{
		system("leaks -q a.out");
		return (0);
	}
	//printeameesta(stack);
	sortlist(&stack, &stack_b);
	//printeameesta(stack);
	//free_nodes(stack);
	//free_nodes(stack_b);
	system("leaks -q a.out");
}

void	free_nodes(t_stack stack)
{
	t_node	*node;
	t_node	*aux;

	node = stack.first;
	while (node != NULL)
	{
		aux = node;
		node = node->next;
		free(aux);
	}
}

void	printeameesta(t_stack stack)
{
	t_node	*node;

	node = stack.first;
	while (node->next != NULL)
	{
		printf("%d\n", node->num);
		node = node->next;
	}
	printf("%d\n\n", node->num);
}

#pragma region Push_numbers

int	check_repeated_numbers(t_stack stack, int num)
{
	t_node	*node;
	int		flag;

	flag = 0;
	node = stack.first;
	while (node->next != NULL)
	{
		if (node->num == num)
			flag = 1;
		node = node->next;
	}
	if (node->num == num)
		flag = 1;
	return (flag);
}

int	control_error(int j, char **str, t_stack *stack, int *flag)
{
	if ((ft_atoi(str[j]) == 0 && *str[j] != '0'))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (*flag != 1)
	{
		*stack = create_stack(ft_atoi(str[j]));
		*flag = 1;
	}
	else
	{
		if (check_repeated_numbers(*stack, ft_atoi(str[j])))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		push(stack, ft_atoi(str[j]));
	}
	return (1);
}

int	push_numbers(int argc, char **argv, t_stack *stack)
{
	int		j;
	char	**str;
	int		*flag;
	int		aux;

	aux = 0;
	flag = &aux;
	if (argc <= 1)
		return (0);
	while (argc > 1)
	{
		j = 0;
		str = ft_split(argv[argc - 1], 32);
		while (str[j] != NULL)
			j++;
		while (--j >= 0)
		{
			if (!check_error(j, str, stack, flag))
				return (0);
		}
		free_entry(str);
		argc--;
	}
	return (1);
}

int	check_error(int j, char **str, t_stack *stack, int *flag)
{
	if (!control_error(j, str, stack, flag))
	{
		free_entry(str);
		return (0);
	}
	return (1);
}

void	free_entry(char **str)
{
	int	j;

	j = 0;
	while (str[j] != NULL)
	{
		free(str[j]);
		str[j] = NULL;
		j++;
	}
	free(str);
	str = NULL;
}

#pragma endregion Push_numbers

int	sortlist(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->first == NULL || is_sort(*stack_a))
		return (0);
	if (stack_a->size == 2)
		swap_a(stack_a, 1);
	else if (stack_a->size <= 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else if (stack_a->size <= 100)
		sort_hundred(stack_a, stack_b);
	else
		sort_hundred(stack_a, stack_b);
	return (0);
}

int	is_sort(t_stack stack_a)
{
	t_node	*node;

	node = stack_a.first;
	while (node->next != NULL)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}
