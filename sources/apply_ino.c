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
	ret |= recurse(foo, node->kinder[e_left]);
	ret |= foo(node->datum);
	ret |= recurse(foo, node->kinder[e_right]);
	return (ret);
}
	
int
	rbt_apply_inord(
		t_applythis foo, void *p_tree)
{
	int		ret;

	ret = 0;
	ret = recurse(foo, ((t_s_rbt*)p_tree)->anchor);
	return (ret);
}
