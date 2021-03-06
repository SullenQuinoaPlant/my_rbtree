/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:35:30 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 07:45:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

t_s_rbtn		*find_node(
	void *key,
	t_rbt_ordering foo,
	t_s_rbtn *at)
{
	t_e_comp	cp;

	while (at)
		if ((cp = (*foo)(key, at->key)) == e_eq)
			break ;
		else
			at = at->kin[cp == e_lt ? e_left : e_right];
	return (at);
}

t_s_rbtn		*next_ino(
	t_s_rbtn *from)
{
	t_s_rbtn	*p;
	t_s_rbtn	*nxt;

	p = from;
	if ((nxt = from->kin[e_right]))
	{
		p = nxt;
		while ((nxt = p->kin[e_left]))
			p = nxt;
	}
	return (p);
}

t_s_rbtn		*prev_ino(
	t_s_rbtn *from)
{
	t_s_rbtn	*p;
	t_s_rbtn	*nxt;

	p = from;
	if ((nxt = from->kin[e_left]))
	{
		p = nxt;
		while ((nxt = p->kin[e_right]))
			p = nxt;
	}
	return (p);
}
