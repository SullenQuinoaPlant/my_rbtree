#include "inner.h"

void					reposition_anchor(
	t_s_rbtn **p_anchor)
{
	t_s_rbtn	*node;
	t_s_rbtn	*up;

	node = *p_anchor;
	while ((up = node->kin[e_parent]))
		node = up;
	*p_anchor = node;
}
