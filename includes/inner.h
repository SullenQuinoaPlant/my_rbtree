/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:25:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:12:51 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INNER_H
# define INNER_H

# include <stdlib.h>

# include "libft.h"
# include "myrbtree.h"

/*
**return values for functions operating on tree:
*/
# define UNROTATED 1
# define ROTATED 2

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

typedef struct s_rbtree_node	t_s_rbtn;
struct							s_rbtree_node
{
	void		*key;
	int			attr;
	t_s_rbtn	*kin[e_tekns_sz];
	void		*datum;
};

typedef struct s_red_black_tree	t_s_rbt;
struct							s_red_black_tree
{
	t_rbt_ordering	order;
	size_t			key_sz;
	t_s_rbtn		*anchor;
	unsigned int	ticker;
};

typedef struct s_applyee_and_arg_package	t_s_apack;
struct							s_applyee_and_arg_package
{
	t_rbt_applyee	f;
	void			*arg;
};

/*
**FUNCTIONS
*/
void							del_node(
	size_t		key_sz,
	t_s_rbtn	*node);

t_s_rbtn						*find_node(
	void			*key,
	t_rbt_ordering	order,
	t_s_rbtn		*at);

void							insert_rebalance(
	t_s_rbtn	*new);

t_s_rbtn						*next_ino(
	t_s_rbtn	*from);

t_s_rbtn						*prev_ino(
	t_s_rbtn	*from);

t_s_rbtn						*rem_reb_blk(
	t_s_rbtn	*weighted_node,
	t_s_rbtn	*black_father,
	t_s_rbtn	*brother,
	int			left_child);

void							rem_reb_red(
	t_s_rbtn	*red_father,
	t_s_rbtn	*brother,
	int			left_child);

void							removal_rebalance(
	t_s_rbtn	*weighted_child);

void							remove_actually(
	t_s_rbtn	*removee,
	t_s_rbt		*tree);

int								remove_node(
	void			*p_key,
	t_s_apack		*foo_and_arg_package,
	void			*p_tree,
	void			**ret_p_datum);

void							reposition_anchor(
	t_s_rbtn		**p_anchor);

void							rotate(
	int			left_or_not,
	t_s_rbtn	*at);

void							rotate_left(
	t_s_rbtn	*at);

void							rotate_right(
	t_s_rbtn	*at);

#endif
