/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:44:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:44:28 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static t_s_rbtn				*greater(
	t_s_rbtn *of)
{
	t_s_rbtn	*ret;

	if ((ret = next_ino(of))->kin[e_right])
	{
		rotate_left(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static t_s_rbtn				*lesser(
	t_s_rbtn *of)
{
	t_s_rbtn	*ret;

	if ((ret = prev_ino(of))->kin[e_left])
	{
		rotate_right(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static t_s_rbtn				*get_replacement(
	t_s_rbtn *of,
	t_s_rbt *tree)
{
	t_s_rbtn	*ret;

	if (tree->ticker++ & 0x1)
		ret = greater(of);
	else
		ret = lesser(of);
	return (ret);
}

static void					swap(
	t_s_rbtn *this,
	t_s_rbtn *forthis,
	size_t key_sz)
{
	if (this == forthis)
		return ;
	ft_cleanfree(this->key, key_sz);
	this->key = forthis->key;
	this->datum = forthis->datum;
}

int							remove_node(
	void *key,
	t_s_apack *foo_pkg,
	void *p_tree,
	void **ret_p_datum)
{
	t_s_rbt *const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*node;
	t_s_rbtn		*rnode;
	int				r;

	if (!(node = find_node(key, tree->order, tree->anchor)))
		return (RBT_KEY_NOT_FOUND);
	rnode = get_replacement(node, tree);
	r = RBT_SUCCESS;
	if (foo_pkg)
		r = (foo_pkg->f)(foo_pkg->arg, node->key, &node->datum);
	if (ret_p_datum)
		*ret_p_datum = node->datum;
	swap(node, rnode, tree->key_sz);
	if (remove_actually(rnode, tree->key_sz) == ROTATED)
		reposition_anchor(&tree->anchor);
	return (r);
}
