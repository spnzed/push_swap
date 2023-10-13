/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:18:15 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/13 20:30:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ft_free_stack hara lo siguiente
//	Crear dos nodos (current y tmp)
//	Comprobar si stack existe
//	En current meteremos stack
//	Recorremos stack
//		En tmp meteremos el next de current
//		Liberamos current
//		igualamos current a tmp
//	Asi cuando no haya next tmp tampoco se hara posible y cuando igualemos current saldremos del bucle
//	Para terminar igualamos el stack a NULO

void ft_free_stack(t_node **stack)
{
	t_node *current;
	t_node *tmp;
	
	if (!stack)
		exit (1);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
