#include "inner.h"

static
int
	recurse(
		t_applythis foo, t_s_rbtn *node)
{
	int		ret;
	int		i;

	ret = 0;
	if (!node)
		return (0);
	ret |= recurse(foo, node->kin[e_right]);
	ret |= recurse(foo, node->kin[e_left]);
	ret |= foo(node->datum);
	return (ret);
}
	
int
	rbt_apply_pstrevord(
		t_applythis foo, void *p_tree)
{
	int		ret;

	ret = 0;
	ret = recurse(foo, ((t_s_rbt*)p_tree)->anchor);
	return (ret);
}
