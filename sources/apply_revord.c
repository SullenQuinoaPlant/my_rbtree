/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_revord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:34:14 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:34:44 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static int				recurse(
	t_rbt_applyee foo,
	t_s_rbtn *node)
{
	int		ret;

	ret = 0;
	if (!node)
		return (0);
	ret |= recurse(foo, node->kin[e_right]);
	ret |= foo(node->key, &node->datum);
	ret |= recurse(foo, node->kin[e_left]);
	return (ret);
}

int						rbt_apply_revord(
	t_rbt_applyee foo,
	void *p_tree)
{
	int		ret;

	ret = 0;
	ret = recurse(foo, ((t_s_rbt*)p_tree)->anchor);
	return (ret);
}
