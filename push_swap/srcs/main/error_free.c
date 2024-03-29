/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:45:58 by aaespino          #+#    #+#             */
/*   Updated: 2023/11/08 16:41:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Index
//	~Free Stacks
//	~Check Syntax Error
//	~Check Duplicate Node
//	~Check MAX Int

//ft_error_free hara lo siguiente
//	usar free_stack
void	ft_error_free(t_node **stack)
{
	ft_free_stack(stack);
	exit (1);
}

//ft_error_syntax hara lo siguiente
//	Comprobar string y comprobar que no ocurra lo siguiente
//		Que el char no sea un numero o un simbolo - +
//		Que el primer char sea + - pero el siguiente no sea un numero
//	Recorrer la string y comprobar que no haya que no sea un numero
//	Si pasa algo asi usaremos error con el error correspondiente
int	ft_error_syntax(char *num)
{
	int	i;

	i = 0;
	if (!((num[0] == '+' || num[0] == '-')
			|| (num[0] >= '0' && num[0] <= '9')))
		return (ft_error_message('1'));
	if ((num[0] == '+' || num[0] == '-')
		&& !(num[1] >= '0' && num[1] <= '9'))
		return (ft_error_message('2'));
	while (num[i])
	{
		if (i == 0 && !((num[i] >= '0' && num[i] <= '9')
				|| (num[i] == '+' || num[i] == '-')))
			return (ft_error_message('2'));
		else if (i != 0 && !(num[i] >= '0' && num[i] <= '9'))
			return (ft_error_message('2'));
		i++;
	}
	return (0);
}

//ft_error_max hara lo siguiente
//	Comprobar que en la strings solo hayan numeros
//	Calculamos los digitos del numero
//	Si son mas de los de LONG_MAX error
//	Metemos el numero con atol
//		Comprobamos que este dentro de los maximos de INT
int	ft_error_max(char *str)
{
	long	nbr;
	long	start;
	int		digits;

	start = ft_num_begins(str);
	digits = ft_strlen(str + start);
	if (digits > 18)
	{
		if (str[0] == '-')
			return (ft_error_message('4'));
		return (ft_error_message('5'));
	}
	nbr = ft_atol(str);
	if (nbr > INT_MAX)
		return (ft_error_message('5'));
	else if (nbr < INT_MIN)
		return (ft_error_message('4'));
	else
		return (0);
}

// -2147483649
//	2147483647

//ft_error_duplicate debera hacer lo siguiente
//	Comprobar que node exista
//	Recorrer node 
//		Si encuentras el num en el nodo
//			retornas error con el mensaje que toque
int	ft_error_duplicate(t_node *node, int num, int index)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->value == num && (index != 0))
			return (ft_error_message('3'));
		node = node->next;
	}
	return (0);
}

void	check_2arg(char **argv, t_node **stack_a, size_t i)
{
	argv = ft_split(argv[1], ' ');
	if (!argv || !*argv)
	{
		ft_error_message('1');
		exit(1);
	}
	if (!argv[1])
	{
		while (i < ft_strlen(argv[0]))
		{
			if (argv[0][i] == '-' || argv[0][i] == '+'
				|| !ft_isdigit(argv[0][i]))
			{
				ft_error_message('1');
				break ;
			}
			i++;
		}
		ft_error_max (argv[0]);
		exit (1);
	}
	gen_stack (stack_a, argv, true);
}
