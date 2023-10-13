/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:48:55 by aaronespino       #+#    #+#             */
/*   Updated: 2023/10/13 20:35:53 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int 			value;
	int 			current_position;
	int 			final_index;
	int 			push_price;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//	main
//	error_free.c
	void		ft_error_free(t_node **stack, char **argv, int flag_argc);
	int 		ft_error_syntax(char *num);
	int 		ft_error_max(char *str);
	void		ft_free_argv(char **argv);
	int 		ft_error_duplicate(t_node *node, int num);
//	gen_stack.c
	int			merge_nodes(t_node **stack, int nbr);
	void		gen_stack(t_node **stack, char **nums, int flag_argc);
//	utils
	int			ft_atoi(const char *str);
	long		ft_atol(const char *str);
	char		**ft_split(char const *s, char c);
	size_t		ft_strlen(const char *str);
//	new utils
	int 		ft_error_message(char num);
	void 		ft_free_stack(t_node **stack);
	t_node		*ft_last_node(t_node *head);
	int 		ft_num_begins(char *str);
	void		ft_lstadd_flinked(t_node **lst, t_node *new);
	int			ft_lst_size(t_node *node);
	t_node 		*ft_lst_last(t_node *node);
	void		ft_putstr_fd(char *s, int fd);
	int			ft_isdigit(int i);


#endif