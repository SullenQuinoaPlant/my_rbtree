/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_preord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:32:41 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:34:58 by nmauvari         ###   ########.fr       */
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
	ret |= foo(node->datum);
	ret |= recurse(foo, node->kin[e_left]);
	ret |= recurse(foo, node->kin[e_right]);
	return (ret);
}

int						rbt_apply_preord(
	t_rbt_applyee foo,
	void *p_tree)
{
	int		ret;

	ret = 0;
	ret = recurse(foo, ((t_s_rbt*)p_tree)->anchor);
	return (ret);
}
