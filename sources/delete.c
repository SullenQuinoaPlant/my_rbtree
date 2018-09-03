#include "inner.h"

void
	del_node(
		t_s_rbtn *node)
{
	if (!node)
		return;
	free(node->key);
	del_node(node->kin[e_left]);
	del_node(node->kin[e_right]);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}
		
void
	rbt_delete(
		void **p_tree)
{
	t_s_rbt * const tree = (t_s_rbt*)*p_tree;

	del_node(tree->anchor);
	ft_cleanfree(tree, sizeof(t_s_rbt));
	*p_tree = 0;
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
	del_node_free(node->kin[e_left]);
	del_node_free(node->kin[e_right]);
	ft_cleanfree(node, sizeof(t_s_rbtn));
}
		
void
	rbt_delete_free(
		size_t datum_sz, void **p_tree)
{
	t_s_rbt * const tree = (t_s_rbt*)*p_tree;

	del_node_free(tree->anchor);
	ft_cleanfree(tree, sizeof(t_s_rbt));
	*p_tree = 0;
}
