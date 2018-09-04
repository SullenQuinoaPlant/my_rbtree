#include "auxilliaries.h"

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
		return (is_good(depth, previous));
	if (!(node->attr & RED))
		depth++;
	ret = 1;
	if ((ret *= recurse(node->kin[e_left], depth, previous))
		ret *= recurse(node->kin[e_right], depth, previous);
	return (ret);
}

int
	uniform_depth(
		t_s_rbt *tree)
{
	int		depth;
	int		ret;

	depth = -1;
	ret = recurse(tree->anchor, 0, &depth);
	return (ret);
}
