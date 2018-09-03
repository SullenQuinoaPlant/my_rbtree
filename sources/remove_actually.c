#include "inner.h"

void
	remove_actually(
		t_s_rbtn *node)
{
	t_s_rbtn	*p;

	if (!(node->attr & RED))
	{
		p = node->kin[e_parent];
		rotate(node->attr & LEFT, p);
		if (!(p->attr & RED))
		{
			p->kin[e_parent].attr |= WEIGHT;
			remove_rebalance(p->kin[e_parent]);
		}
		p->attr &= ~RED;
	}
	p->kin[node->attr & LEFT ? e_left : e_right] = 0;
	ft_cleanfree(node->key, key_sz);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}
