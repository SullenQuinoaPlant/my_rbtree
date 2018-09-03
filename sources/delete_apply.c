#include "inner.h"

static
int
	del_node(
		int (*foo)(void*),
		t_s_rbtn *node)
{
	int		ret;
	int		i;

	ret = 0;
	if (!node)
		return (ret);
	i = -1;
	while (!ret && (++i) < e_tecns_sz)
	{
		ret |= del_node(foo, node->kin[i];
		node->kin[i] = 0;
	}
	if (i == e_tecns_sz)
	{
		free(node->key);
		ft_cleanfree(node, sizeof(t_s_rbtn));
	}
}
		
int
	rbt_delete_apply_ino(
		int (*foo)(void*),
		void	**p_tree)
{
	t_s_rbt	* const tree = (t_s_rbt*)*p_tree;
	int		ret;

	ret = 0;
	if (!(ret |= del_node(foo, tree->anchor)))
	{
		ft_cleanfree(tree, sizeof(t_s_rbt));
		*p_tree = 0;
	}
	return (ret);
}
