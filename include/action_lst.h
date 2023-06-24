/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:27:22 by aaronespino       #+#    #+#             */
/*   Updated: 2023/06/25 00:58:20 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_LST_H
# define ACTION_LST_H

# include "push_swap.h"

typedef struct lst_actions
{
	int	*ra;
	int	*rb;
	int	*rra;
	int	*rrb;
	int	*rr;
	int	*rrr;
}	t_actions;

void	actions_init(t_actions **actions);
void	actions_clear(t_actions **actions);

#endif
