#include "inner.h"

void					removal_rebalance(
	t_s_rbtn	*p0)
{
	t_s_rbtn	*p1;
	t_s_rbtn	*p2;
	t_s_rbtn	*p3;
	int			left;

	while ((p1 = p0->kin[e_parent]))
	{
		left = p0->attr & LEFT;
		p2 = p1->kin[left ? e_right : e_left];
		if (p1->attr & RED)
		{
			rem_reb_red(p1, p2, left);
			break;
		}
		else
			p0 = rem_reb_blk(p1, p2, left);
	}
}
