/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_apply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:55:42 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:57:55 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static int			recurse(
	int (*foo)(void*),
	t_s_rbtn *node)
{
	int		ret;

	ret = 0;
	if (!node)
		return (ret);
	if (!(ret = recurse(foo, node->kin[e_left])))
		node->kin[e_left] = 0;
	if (!ret && !(ret = recurse(foo, node->kin[e_right])))
		node->kin[e_right] = 0;
	if (!ret)
		ret = (*foo)(node->datum);
	if (!ret)
	{
		free(node->key);
		ft_cleanfree(node, sizeof(t_s_rbtn));
	}
	return (ret);
}

int					rbt_delete_apply_postord(
	int (*foo)(void*),
	void **p_tree)
{
	t_s_rbt *const	tree = (t_s_rbt*)*p_tree;
	int				ret;

	ret = 0;
	if (!(ret |= recurse(foo, tree->anchor)))
	{
		ft_cleanfree(tree, sizeof(t_s_rbt));
		*p_tree = 0;
	}
	return (ret);
}
