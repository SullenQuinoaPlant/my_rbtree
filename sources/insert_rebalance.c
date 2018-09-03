#include "inner.h"

static
void
	red_uncle(
		t_s_rbtn parent, t_s_rbtn grandpa, t_s_rbtn uncle)
{
	uncle->attr &= ~RED;
	grandpa->attr |= RED;
	parent->attr &= ~RED;
	insert_rebalance(grandpa);
}

static
void
	black_uncle(
		t_s_rbtn p0, t_s_rbtn p1,
		t_s_rbtn p2, t_s_rbtn p3)
{
	if ((p0->attr & LEFT) ^ (p1->attr & LEFT))
	{
		p0 &= ~RED;
		rotate(p1->attr & LEFT, p1);
	}
	else
		p1 &= ~RED;
	p2->attr |= RED;
	rotate(!(p1->attr & LEFT), p2);
}

void
	insert_rebalance(
		t_s_rbtn *new)
{
	t_s_rbtn	*p1;
	t_s_rbtn	*p2;
	t_s_rbtn	*p3;

	if (!(p1 = new->kin[e_parent]))
		;
	else if (!(p1->attr & RED))
		;
	else if (!(p2 = p1->kin[e_parent]))
		p1->attr &= ~RED;
	else if ((p3 = (p2->kin[p1->attr & LEFT ? e_right : e_left])) &&
		p3->attr & RED)
		red_uncle(p1, p2, p3);
	else
		black_uncle(p1, p2, p3);
}