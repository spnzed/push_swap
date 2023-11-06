/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:29:41 by aaronespino       #+#    #+#             */
/*   Updated: 2023/11/06 12:44:13 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_stacks(t_node *stack_a, t_node *stack_b, bool flag)
{
	if (flag == false)
	{
		stack_a = malloc(sizeof(t_node));
		if (!stack_a)
			return (NULL);
		stack_a->is_end = true;
		return (stack_a);
	}
	else
	{
		stack_b = malloc(sizeof(t_node));
		if (!stack_b)
		{
			ft_free_stack(&stack_a);
			return (NULL);
		}
		stack_b->is_end = true;
		return (stack_b);
	}
}

static void	arguments_check(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return ;
}

static void	fill_stack(int argc, char **argv, t_node **stack_a)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		gen_stack (stack_a, argv + 1, true);
	}
	else
		gen_stack (stack_a, argv, false);
}

static void	init_sorts(t_node **a, t_node **b, t_node *A, t_node *B)
{
	if (!ft_lst_sorted(*a))
	{
		if (ft_lst_size(*a) == 2)
			sa(a);
		else if (ft_lst_size(*a) == 3)
			ft_lil_sort(a);
		else
			ft_sort(a, b);
	}
	ft_free_stack(a);
	ft_free_stack(&A);
	ft_free_stack(&B);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*first_a;
	t_node	*first_b;

	stack_a = NULL;
	stack_b = NULL;
	first_a = NULL;
	first_b = NULL;
	arguments_check(argc, argv);
	stack_a = init_stacks(stack_a, stack_b, false);
	if (stack_a)
		stack_b = init_stacks(stack_a, stack_b, true);
	if (stack_a && stack_b)
	{
		first_a = stack_a;
		first_b = stack_b;
		fill_stack(argc, argv, &stack_a);
		init_sorts(&stack_a, &stack_b, first_a, first_b);
		return (0);
	}
	return (12);
}
