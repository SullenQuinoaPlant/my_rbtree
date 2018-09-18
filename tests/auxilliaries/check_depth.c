#include "aux_inner.h"

static
int
	is_good(
		int depth, int *previous)
{
	if (*previous == -1)
		*previous = depth;
	return (depth == *previous);
}

static
int
	recurse(
		t_s_rbtn *node, int depth, int *previous)
{
	int		ret;

	if (!node)
	{
		if (!is_good(depth, previous))
			return (BLACK_VIOLATION);
		else
			return (0);
	}
	if (!(node->attr & RED))
		depth++;
	else if (node->kin[e_parent] &&
		node->kin[e_parent]->attr & RED)
		return (RED_VIOLATION);
	ret = 0;
	if (!(ret = recurse(node->kin[e_left], depth, previous)))
		ret = recurse(node->kin[e_right], depth, previous);
	return (ret);
}

int
	uniform_depth(
		t_s_rbt *tree, int *ret_depth)
{
	int		depth;
	int		ret;

	depth = -1;
	ret = recurse(tree->anchor, 0, &depth);
	if (ret_depth)
		*ret_depth = depth;
	return (ret);
}
