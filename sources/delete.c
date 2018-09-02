#include "inner.h"

static
void
	del_node(
		t_s_rbtn *node)
{
	if (!node)
		return;
	free(node->key);
	ft_bzero(node, sizeof(t_s_rbtn));
}
		
void
	rbt_delete(
		t_s_rbt *tree)
{
	del_node(tree->anchor);
	rbt_init(0, 0, tree);
}

static
void
	del_node_free(
		t_s_rbtn *node, size_t datum_sz)
{
	if (!node)
		return;
	free(node->key);
	ft_cleanfree(node->datum, datum_sz);
	ft_bzero(node, sizeof(t_s_rbtn));
}
		
void
	rbt_delete_free(
		size_t datum_sz, t_s_rbt *tree)
{
	del_node_free(tree->anchor, datum_sz);
	rbt_init(0, 0, tree);
}
