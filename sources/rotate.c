#include "inner.h"

void
	rotate_left(
		t_s_rbtn *at)
{
	t_s_rbtn	tmp;
	t_s_rbtn	*p;

	tmp = *at;
	at->attr |= LEFT;
	at->kin[e_parent] = at->kin[e_right];
	p = tmp.kin[e_right]->kin[e_left];
	at->kin[e_right] = p;
	p->kin[e_parent] = at;
	p->attr &= ~LEFT;
	p = tmp.kin[e_right];
	p->kin[e_parent] = tmp.kin[e_parent];
	p->kin[e_left] = at;
	p->attr &= ~LEFT;
	p->attr |= (tmp.attr & LEFT);
}

void
	rotate_right(
		t_s_rbtn *at)
{
	t_s_rbtn	tmp;
	t_s_rbtn	*p;

	tmp = *at;
	at->attr &= ~LEFT;
	at->kin[e_parent] = at->kin[e_left];
	p = tmp.kin[e_left]->kin[e_right];
	at->kin[e_left] = p;
	p->kin[e_parent] = at;
	p->attr |= LEFT;
	p = tmp.kin[e_left];
	p->kin[e_parent] = tmp.kin[e_parent];
	p->kin[e_right] = at;
	p->attr &= ~LEFT;
	p->attr |= (tmp.attr & LEFT);
}

void
	rotate(
		int left, t_s_rbtn *at)
{
	if (left)
		rotate_left(at);
	else
		rotate_right(at);
}
