/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:10:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/16 22:29:09 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argv(char **argv)
{
	int i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		exit(1);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv - 1);
}
