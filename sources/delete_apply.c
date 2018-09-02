#include "inner.h"

static
int
	del_node(
		int (*foo)(void*),
		t_s_rbtn *node)
{
	int		ret;

	ret = 0;
	if (!node)
		return (ret);
	ret |= del_node(foo, node->kinder[e_left]
	while (
	ret |= del_node(node->
	ft_bzero(node, sizeof(t_s_rbtn));
	free(node->key);
}
		
int
	rbt_delete_apply_ino(
		int (*foo)(void*),
		t_s_rbt *tree)
{
	int		ret;

	ret = 0;
	ret |= del_node(foo, tree->anchor);
	rbt_init(0, 0, tree);
	return (ret);
}
