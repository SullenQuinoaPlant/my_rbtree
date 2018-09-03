#include "inner.h"

int
	insert_rebalance(
		t_s_rbtn *new)
{
	t_s_rbtn	*p1;
	t_s_rbts	*p2;

	if (!(p1 = new->kin[e_parent]))
		return (RBT_SUCCESS);
	else if (!(p1->attributes & RED))
		return (RBT_SUCCESS);
	else if (!(p2 = p1->kin[e_parent]))
		p1->attributes &= ~RED;
	else if (p2->kin[p1->attributes & LEFT ? e_right : e_left
}
