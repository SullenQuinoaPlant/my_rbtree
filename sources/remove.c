#include "inner.h"

static
t_s_rbtn
	*greater(
		t_s_rbtn *of)
{
	t_s_rbtn	*ret;

	if ((ret = next_ino(of))->kin[e_right])
	{
		rotate_left(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static t_s_rbtn				*lesser(
	t_s_rbtn	*of)
{
	t_s_rbtn	*ret;

	if ((ret = prev_ino(of))->kin[e_left])
	{
		rotate_right(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static t_s_rbtn				*get_replacement(
	t_s_rbtn	*of,
	t_s_rbt		*tree)
{
	t_s_rbtn	*ret;

	if (tree->ticker++ & 0x1)
		ret = greater(of);
	else
		ret = lesser(of);
	return (ret);
}

static void				swap(
	t_s_rbtn	*this,
	t_s_rbtn	*forthis,
	size_t		key_sz)
{
	if (this == forthis)
		return;
	ft_cleanfree(this->key, key_sz);
	this->key = forthis->key;
	this->datum = forthis->datum;
}

int						remove(
	void			*key,
	void			*p_tree,
	t_rbt_applyee	foo,
	void			**ret_p_datum)
{
	t_s_rbt * const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*node;
	t_s_rbtn		*rnode;
	int				r;

	if (!(node = find_node(key, tree->order_foo, tree->anchor)))
		return (RBT_KEY_NOT_FOUND);
	rnode = get_replacement(node);
	r = RBT_SUCCESS;
	if (foo)
		r = (*foo)(node->datum);
	if (ret_p_datum)
		*ret_p_datum = node->datum;
	swap(node, rnode, tree->key_sz);
	remove_actually(rnode, tree->key_sz);
	return (r);
}
