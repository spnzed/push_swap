/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:16:38 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/05 19:34:08 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Create Stack
//Checks
//	~Duplicates
//	~Oveflow/Underflow
//	~Syntax Error

#include "push_swap.h"
//atol chill
static long	ft_atol(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

//find_last_node debe hacer
//Recorre la lista hasta encontrar el ultimo
//	Entonces lo devuelves
t_node	*find_last_node(t_node *head)
{
	if (!head)
		return (0);
	while (head->next);
		head = head->next;
	return (head);
}

//merge_nodes hace
//	inicia node y last_node
//	Comprueba si stack existe
//	Reserva memoria para un un nodo
//	Iguala el nodo al nbr y el siguiente a NULL
//	Si el punteto de stack no existe
//		Metemos nodo al puntero de stack
//		el previo es null (porque seria el primero)
//	Si no es el caso
//		el ultimo nodo sera last_node del stack
//		el siguiente sera node
//		el previo sera last_node
void	merge_nodes(t_node **stack, int nbr)
{
	t_node	*node;
	t_node	*last_node;
	
	if (!stack)
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		last_node->prev = last_node;
	}
}

//gen_stack debe hacer
//	Recorrer el array
//		Liberas despues de cada comprobacion
//		Comprobar syntax
//		Comprobar limites de int
// 		Comprobar duplicados
// 	Merge_Nodes
void	gen_stack(t_node **stack, char **nums)
{
	long	nbr;
	int		i;

	i = 0;
	while (nums[i])
	{
		if (ft_error_syntax(nums[i]))
			error_free(stack, nums);
		nbr = ft_atol(nums[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error_free(stack, nums);
		if (ft_error_duplicate(*stack, (int)nbr))
			ft_error_free(stack, nums);
		merge_nodes(*stack, (int)nbr);
		i++;
	}
}