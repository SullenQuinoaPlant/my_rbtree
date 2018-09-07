/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:54:30 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:07:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void			del_node(
	size_t key_sz,
	t_s_rbtn *node)
{
	if (!node)
		return ;
	ft_cleanfree(node->key, key_sz);
	del_node(key_sz, node->kin[e_left]);
	del_node(key_sz, node->kin[e_right]);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}

void			rbt_delete(
	void **p_tree)
{
	t_s_rbt *const	tree = (t_s_rbt*)*p_tree;

	del_node(tree->key_sz, tree->anchor);
	ft_cleanfree(tree, sizeof(t_s_rbt));
	*p_tree = 0;
}

static void		del_node_free(
	size_t datum_sz,
	t_s_rbtn *node)
{
	if (!node)
		return ;
	free(node->key);
	ft_cleanfree(node->datum, datum_sz);
	del_node_free(datum_sz, node->kin[e_left]);
	del_node_free(datum_sz, node->kin[e_right]);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}

void			rbt_delete_free(
	size_t datum_sz,
	void **p_tree)
{
	t_s_rbt *const	tree = (t_s_rbt*)*p_tree;

	del_node_free(datum_sz, tree->anchor);
	ft_cleanfree(tree, sizeof(t_s_rbt));
	*p_tree = 0;
}
