/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:58 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/05 17:15:09 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include "push_swap.h"

void ft_free_stack(t_node **stack)
{
	t_node *current;
	t_node *tmp;
	
	if (!stack)
		return (0);
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void ft_error_free(t_node **stack, char **argv)
{
	free_stack(stack);
	exit (1);
}

int ft_error_syntax(char *num)
{
	int i;
	
	i = 0;
	if (!(num[0] == '+' || num[0] == '-' ||
		(num[0] >= '0' && num[0] <= '9')))
		return (error_message('1'));
	if ((num[0] == '+' || num[0] == '-') &&
		!(num[1] >= '0' && num[1] <= '9'))
		return (error_message('1'));
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (error_message('1'));
		i++;
	}
	return (0);
}

int ft_error_duplicate(t_node *node, int num)
{
	if (!node)
		return(0);
	while(node)
	{
		if (node->value = num)
			return (error_message('2'));
		node = node->next;
	}
	return (0);
}
