#include "inner.h"

void					removal_rebalance(
	t_s_rbtn	*p0)
{
	t_s_rbtn	*p1;
	int			left_child;

	while (p0 && (p1 = po->kin[e_parent]))
	{
		left_child = p0->attr & LEFT);
		if (p1->attr & RED)
			p0 = rem_reb_red(p0, p1, left_child);
		else
			po = rem_reb_black(p0, p1, left_child);
	}
}
