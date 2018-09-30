/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removal_rebalance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:45 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:56:47 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void					removal_rebalance(
	t_s_rbtn *p0)
{
	t_s_rbtn	*p1;
	t_s_rbtn	*p2;
	int			left;

	while ((p1 = p0->kin[e_parent]))
	{
		left = p0->attr & LEFT;
		p2 = p1->kin[left ? e_right : e_left];
		if (p1->attr & RED)
		{
			rem_reb_red(p1, p2, left);
			break ;
		}
		else if (!(p0 = rem_reb_blk(p0, p1, p2, left)))
			break ;
	}
}
