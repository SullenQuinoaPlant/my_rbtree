/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:59:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:06:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static int					insert(
	t_s_rbtn *this,
	t_rbt_ordering with,
	t_s_rbtn **in)
{
	t_e_comp	cmp;
	int			r;

	while (*in)
	{
		if ((cmp = (*with)(this->key, (*in)->key)) == e_eq)
			return (RBT_DUP_KEY);
		else if (cmp == e_lt)
			this->attr |= LEFT;
		else
			this->attr &= ~LEFT;
		this->kin[e_parent] = *in;
		in = &((*in)->kin[cmp == e_lt ? e_left : e_right]);
	}
	*in = this;
	insert_rebalance(this);
	return (RBT_SUCCESS);
}

int							rbtn_insert(
	void *datum,
	void *key,
	void *p_tree)
{
	t_s_rbt *const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*new;
	int				r;

	if (!key || !p_tree)
		return (RBT_BAD_ARG);
	if ((new = malloc(sizeof(t_s_rbtn))) &&
		(new->key = malloc(tree->key_sz)))
	{
		ft_memcpy(new->key, key, tree->key_sz);
		new->attr = RED;
		ft_bzero(new->kin, sizeof(new->kin));
		new->datum = datum;
		if ((r = (insert(new, tree->order, &tree->anchor) == RBT_DUP_KEY)))
			del_node(tree->key_sz, new);
		else
			reposition_anchor(&tree->anchor);
		return (r);
	}
	else if (new)
		free(new);
	return (RBT_SYS_ERR);
}
