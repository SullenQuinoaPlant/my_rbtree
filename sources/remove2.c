/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 08:00:34 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:00:35 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void					remove_actually(
	t_s_rbtn *p0,
	t_s_rbt *tree)
{
	t_s_rbtn	*p1;

	if ((p1 = p0->kin[e_parent]))
	{
		if (!(p0->attr & RED))
		{
			removal_rebalance(p0);
			if ((p1 = p0->kin[e_parent]) &&
				p1->attr & RED)
				rotate(p0->attr & LEFT, p1);
			reposition_anchor(&tree->anchor);
		}
		p1->kin[p0->attr & LEFT ? e_left : e_right] = 0;
	}
	else
		tree->anchor = 0;
	ft_cleanfree(p0, sizeof(t_s_rbtn));
}
