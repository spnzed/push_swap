/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genstack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:16:38 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/01 16:24:27 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Index
//	~Joins nodes with nbrs
//	~Genera el Stack

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

	if (!stack)
		exit (1) ;
	node = malloc(sizeof(t_node));
	if (!node)
		exit (1);
	node->next = NULL;
	node->value = nbr;
	if ((*stack)->is_end)
		*stack = node;
	else
		ft_lstadd_blinked(stack, node);
}

//gen_stack debe hacer
//	Recorrer el array
//		Liberas despues de cada comprobacion
//		Comprobar syntax
//		Comprobar limites de int
// 		Comprobar duplicados
// 	Merge_Nodes
void	gen_stack(t_node **stack, char **nums, bool argc2)
{
	int	nbr;
	int	i;

	i = 1;
	while (nums[i])
	{
		if (ft_error_syntax(nums[i]))
			ft_error_free(stack, nums, argc2);
		if (ft_error_max(nums[i]))
			ft_error_free(stack, nums, argc2);
		nbr = ft_atoi(nums[i]);
		if (ft_error_duplicate(*stack, (int)nbr))
			ft_error_free(stack, nums, argc2);
		merge_nodes(stack, nbr);
		i++;
	}
	if (argc2 == true)
		ft_free_argv(nums);
}
