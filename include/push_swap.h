/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/05 19:17:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

typedef struct s_node
{
	int 	value;
	int 	current_position;
	int 	final_index;
	int 	push_price;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}	t_node;

//Generar stack
void		gen_stack(t_node **stack, char **nums);
	static long	ft_atol(const char *str);
	//comprovations
	int 	ft_error_syntax(char *num);
	int 	ft_error_duplicate(t_node *node, int num);
	void 	ft_error_free(t_node **stack, char **argv);
	void 	ft_free_stack(t_node **stack);
	//merge inputs in stack
	void	merge_nodes(t_node **stack, int nbr);
		t_node	*find_last_node(t_node *head);

		

	




	


#endif