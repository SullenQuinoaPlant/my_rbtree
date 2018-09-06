#include "inner.h"

void					removal_rebalance(
	t_s_rbtn	*p0)
{
	t_s_rbtn	*p1;

	p1 = p0->kin[e_parent];
	if (p1->attr & RED)
		rem_reb_red(p0, p1);
	else
		rem_reb_black(p0, p1);
}

void					remove_actually(
	t_s_rbtn	*p0,
	size_t		key_sz)
{
	t_s_rbtn	*p1;

	p1 = p0->kin[e_parent];
	p1->kin[p0->attr & LEFT ? e_left : e_right] = 0;
	if (!(p0->attr & RED))
	{
		rotate(p0->attr & LEFT, p1);
		if (!(p1->attr & RED))
			removal_rebalance(p1->kin[e_parent]);
		p1->attr &= ~RED;
	}
	ft_cleanfree(p0->key, key_sz);
	ft_cleanfree(p0, sizeof(t_s_rbtn));
}
