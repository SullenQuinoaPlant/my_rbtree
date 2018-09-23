/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_prerevord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:33:31 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:34:02 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static int				recurse(
	t_rbt_applyee foo,
	void *foo_arg,
	t_s_rbtn *node)
{
	int		ret;

	ret = 0;
	if (!node)
		return (0);
	ret |= foo(foo_arg, node->key, &node->datum);
	ret |= recurse(foo, foo_arg, node->kin[e_right]);
	ret |= recurse(foo, foo_arg, node->kin[e_left]);
	return (ret);
}

int						rbt_apply_prerevord(
	t_rbt_applyee foo,
	void *foo_arg,
	void *p_tree)
{
	int		ret;

	ret = 0;
	ret = recurse(foo, foo_arg, ((t_s_rbt*)p_tree)->anchor);
	return (ret);
}
