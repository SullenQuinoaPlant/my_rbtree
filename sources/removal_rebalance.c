#include "inner.h"

void					removal_rebalance(
	t_s_rbtn	*p0)
{
	t_s_rbtn	*p1;
	t_s_rbtn	*p2;
	t_s_rbtn	*p3;
	int			left;

	while ((p1 = po->kin[e_parent]))
	{
		left = p0->attr & LEFT;
		p2 = p1->kin[left ? e_right : e_left];
		if ((p3 = p2->kin[left ? e_left : e_right])) &&
			p3->attr & RED)
			inner_red_nephew(
		if (p1->attr & RED)
		{
			rem_reb_red(p1, left);
			break;
		}
		else if ((p0 = rem_reb_black(p0, p1, left))

		if (p0->attr & RED && (p0->attr &= ~RED))
			break;
			
	}
}
