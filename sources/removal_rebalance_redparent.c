/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removal_rebalance_redparent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:49:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:57:08 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

static void			no_red(
	t_s_rbtn *p1,
	t_s_rbtn *p2)
{
	p2->attr |= RED;
	p1->attr &= ~RED;
}

static void			outer_red_nephew(
	t_s_rbtn *p1,
	t_s_rbtn *p2,
	t_s_rbtn *p3,
	int left)
{
	p1->attr &= ~RED;
	p2->attr |= RED;
	p3->attr &= ~RED;
	rotate(left, p1);
}

static void			inner_red_nephew(
	t_s_rbtn *p1,
	t_s_rbtn *p2,
	int left)
{
	p1->attr &= ~RED;
	rotate(!left, p2);
	rotate(left, p1);
}

void				rem_reb_red(
	t_s_rbtn *p1,
	t_s_rbtn *p2,
	int left)
{
	t_s_rbtn	*p3;

	if ((p3 = p2->kin[left ? e_left : e_right]) &&
		p3->attr & RED)
		inner_red_nephew(p1, p2, left);
	else if ((p3 = p2->kin[left ? e_right : e_left]) &&
		p3->attr & RED)
		outer_red_nephew(p1, p2, p3, left);
	else
		no_red(p1, p2);
}
