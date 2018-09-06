/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:25:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/06 06:50:37 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNER_H
# define INNER_H

# include <stdlib.h>

# include "libft.h"
# include "myrbtree.h"

typedef enum e_color			t_e_col;
enum							e_color {
	e_red,
	e_black
};

typedef enum e_kin_nodes		t_e_kns;
enum							e_kin_nodes {
	e_parent,
	e_left,
	e_right,
	e_tekns_sz
};

/*
**node attribute flags:
**see (t_s_rbtn).attr
*/
# define RED 0X01
# define LEFT 0X02
# define WEIGHT 0X04

typedef struct s_rbtree_node	t_s_rbtn;
struct							s_rbtree_node {
	void		*key;
	int			attr;
	t_s_rbtn	*kin[e_tekns_sz];
	void		*datum;
};

typedef struct s_red_black_tree	t_s_rbt;
struct							s_red_black_tree {
	t_rbt_ordering	order;
	size_t			key_sz;
	t_s_rbtn		*anchor;
	unsigned int	ticker;
};

/*
**FUNCTIONS
*/
void							del_node(
	size_t		key_sz,
	t_s_rbtn	*node);

t_s_rbtn						*find_node(
	void			*key,
	t_rbt_ordering	foo,
	t_s_rbtn		*at);

void							insert_rebalance(
	t_s_rbtn	*new);

t_s_rbtn						*next_ino(
	t_s_rbtn	*from);

t_s_rbtn						*prev_ino(
	t_s_rbtn	*from);

void							rem_reb_red(
	t_s_rbtn	*focus,
	t_s_rbtn	*red_parent);

void							removal_rebalance(
	t_s_rbtn	*p0);

int								remove(
	void			*at_key,
	t_rbt_applyee	foo,
	void			*p_tree,
	void			**ret_p_datum);

void							remove_actually(
	t_s_rbtn	*removee);

void							rotate(
	int			left_or_not,
	t_s_rbtn	*at);

void							rotate_left(
	t_s_rbtn	*at);

void							rotate_right(
	t_s_rbtn	*at);

#endif
