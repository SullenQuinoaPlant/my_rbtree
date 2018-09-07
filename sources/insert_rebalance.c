/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_rebalance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:56:11 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:56:13 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

/*
**p0 : current node
**p1 : father
**p2 : grandfather
**p3 : uncle
*/

static void					red_uncle(
	t_s_rbtn *p1,
	t_s_rbtn *p2,
	t_s_rbtn *p3)
{
	p3->attr &= ~RED;
	p2->attr |= RED;
	p1->attr &= ~RED;
	insert_rebalance(p2);
}

static void					black_uncle(
	t_s_rbtn *p0,
	t_s_rbtn *p1,
	t_s_rbtn *p2)
{
	if ((p0->attr & LEFT) ^ (p1->attr & LEFT))
	{
		p0->attr &= ~RED;
		rotate(p1->attr & LEFT, p1);
	}
	else
		p1->attr &= ~RED;
	p2->attr |= RED;
	rotate(!(p1->attr & LEFT), p2);
}

void						insert_rebalance(
	t_s_rbtn *p0)
{
	t_s_rbtn	*p1;
	t_s_rbtn	*p2;
	t_s_rbtn	*p3;

	if (!(p1 = p0->kin[e_parent]))
		;
	else if (!(p1->attr & RED))
		;
	else if (!(p2 = p1->kin[e_parent]))
		p1->attr &= ~RED;
	else if ((p3 = (p2->kin[p1->attr & LEFT ? e_right : e_left])) &&
		p3->attr & RED)
		red_uncle(p1, p2, p3);
	else
		black_uncle(p0, p1, p2);
}
