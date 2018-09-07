/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:16:51 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:45:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

int		rbtn_retrieve(
	void *key,
	void *p_tree,
	void **ret_p_datum)
{
	t_s_rbt *const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*p;

	if (ret_p_datum)
		*ret_p_datum = 0;
	if (!p_tree || !ret_p_datum)
		return (RBT_BAD_ARG);
	p = find_node(key, tree->order, tree->anchor);
	if (!p)
		return (RBT_KEY_NOT_FOUND);
	else
		*ret_p_datum = p->datum;
	return (RBT_SUCCESS);
}
