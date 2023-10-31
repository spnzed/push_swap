/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:10:37 by aaespino          #+#    #+#             */
/*   Updated: 2023/10/31 19:00:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_argv(char **argv)
{
	int i;

	i = 1;
	if (argv == NULL || *argv == NULL)
		exit(1);
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv - 1);
}
