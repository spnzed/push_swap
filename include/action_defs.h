/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:27:01 by aaronespino       #+#    #+#             */
/*   Updated: 2023/09/29 16:04:48 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_DEFS_H
# define ACTION_DEFS_H

# define SWAP_A 'A'
# define PUSH_A 'B'
# define ROTATE_A 'C'
# define REV_ROTATE_A 'D'
# define SWAP_B 'E'
# define PUSH_B 'F'
# define ROTATE_B 'G'
# define REV_ROTATE_B 'H'
# define SWAP_S 'I'
# define ROTATE_R 'J'
# define REV_ROTATE_R 'K'

void			swap_a(t_stack *stk, int print);
void			swap_b(t_stack *stk, int print);
void			swap_s(t_stack *stk, int print);

void			push_a(t_stack *stk, int print);
void			push_b(t_stack *stk, int print);

void			rotate_a(t_stack *stk, int print);
void			rotate_b(t_stack *stk, int print);
void			rotate_r(t_stack *stk, int print);

void			reverse_rotate_a(t_stack *stk, int print);
void			reverse_rotate_b(t_stack *stk, int print);
void			reverse_rotate_r(t_stack *stk, int print);

#endif