#include "inner.h"

static
void
	removal_rebalance(
		t_s_rbtn *p0)
{
	t_s_rbtn	*p1;

	p1 = p0->kin[e_parent];
	if (p1->attr & RED)
		rem_reb_red(p0, p1);
	else
		rem_reb_black(p0, p1);
}

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
			removal_rebalance(p->kin[e_parent]);
		p->attr &= ~RED;
	}
	p->kin[node->attr & LEFT ? e_left : e_right] = 0;
	ft_cleanfree(node->key, key_sz);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}
