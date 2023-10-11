/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:16:38 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/11 16:45:29 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Index
//	~Joins nodes with nbrs
//	~Genera el Stack

#include "push_swap.h"

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
		node->prev = last_node;
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
		if (ft_error_max(nums[i]))
			ft_error_free(stack, nums);
		nbr = ft_atoi(nums[i]);
		if (ft_error_duplicate(*stack, nbr))
			ft_error_free(stack, nums);
		merge_nodes(*stack, nbr);
		i++;
	}
}
