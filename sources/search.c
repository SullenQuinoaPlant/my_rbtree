#include "inner.h"

t_s_rbtn
	*find_node(
		void *key, t_rbt_ordering foo,
		t_s_rbtn *at)
{
	t_e_comp	cmp;

	if (!at)
		return (0);
	if ((cmp = (*foo)(key, at->key)) == e_eq)
		return (at);
	return (find_node(key, foo, at->kin[cmp == e_lt ? e_left : e_right]));
}

t_s_rbtn
	*next_ino(
		t_s_rbtn *from)
{
	t_s_rbtn	*p;
	t_s_rbtn	*nxt;

	p = from->kin[e_right];
	while ((nxt = p->kin[e_left]))
		p = nxt;
	return (p);
}

t_s_rbtn
	*prev_ino(
		t_s_rbtn *from)
{
	t_s_rbtn	*p;
	t_s_rbtn	*nxt;

	p = from->kin[e_left];
	while ((nxt = p->kin[e_right]))
		p = nxt;
	return (p);
}
