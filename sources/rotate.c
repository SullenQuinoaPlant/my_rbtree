/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:37:36 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/11 11:57:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

void	rotate_left(
	t_s_rbtn *at)
{
	t_s_rbtn	tmp;
	t_s_rbtn	*p;

	tmp = *at;
	if ((p = at->kin[e_parent]))
		p->kin[tmp.attr & LEFT ? e_left : e_right] = tmp.kin[e_right];
	at->attr |= LEFT;
	at->kin[e_parent] = at->kin[e_right];
	p = tmp.kin[e_right]->kin[e_left];
	if ((at->kin[e_right] = p))
	{
		p->kin[e_parent] = at;
		p->attr &= ~LEFT;
	}
	p = tmp.kin[e_right];
	p->kin[e_parent] = tmp.kin[e_parent];
	p->kin[e_left] = at;
	p->attr &= ~LEFT;
	p->attr |= (tmp.attr & LEFT);
}

void	rotate_right(
	t_s_rbtn *at)
{
	t_s_rbtn	tmp;
	t_s_rbtn	*p;

	tmp = *at;
	if ((p = at->kin[e_parent]))
		p->kin[tmp.attr & LEFT ? e_left : e_right] = tmp.kin[e_left];
	at->attr &= ~LEFT;
	at->kin[e_parent] = at->kin[e_left];
	p = tmp.kin[e_left]->kin[e_right];
	if ((at->kin[e_left] = p))
	{
		p->kin[e_parent] = at;
		p->attr |= LEFT;
	}
	p = tmp.kin[e_left];
	p->kin[e_parent] = tmp.kin[e_parent];
	p->kin[e_right] = at;
	p->attr &= ~LEFT;
	p->attr |= (tmp.attr & LEFT);
}

void	rotate(
	int left,
	t_s_rbtn *at)
{
	if (left)
		rotate_left(at);
	else
		rotate_right(at);
}
