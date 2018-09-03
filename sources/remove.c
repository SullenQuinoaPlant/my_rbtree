#include "inner.h"

static
t_s_rbtn
	*next(
		t_s_rbtn *for)
{
	t_s_rbtn	*ret;

	if ((ret = next_ino(for))->kin[e_right])
	{
		rotate_left(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static
t_s_rbtn
	*previous(
		t_s_rbtn *for)
{
	t_s_rbtn	*ret;

	if ((ret = next_ino(for))->kin[e_right])
	{
		rotate_left(ret);
		ret->attr |= RED;
		ret->kin[e_parent]->attr &= ~RED;
	}
	return (ret);
}

static
t_s_rbtn
	*get_replacement(
		t_s_rbtn *for, t_s_rbt *tree)
{
	t_s_rbtn	*ret;

	ret = 0;
	if (for->kin[e_left] == 0)
		ret = for->kin[e_right];
	else if (for->kin[e_right] == 0)
		ret = for->kin[e_left];
	else if (tree->ticker++ & 0x1)
		ret = next(for);
	else
		ret = previous(for);
	return (ret);
}

static
void
	swap(
		t_s_rbtn *this, t_s_rbtn *forthis,
		t_s_rbt *in)
{
	ft_cleanfree(this->key, in->key_sz);
	this->key = forthis->key;
	this->datum = forthis->datum;
}

int
	remove_node(
		void *key, void *p_tree,
		t_rbt_applyee foo, void **ret_p_datum)
{
	t_s_rbt * const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*node;
	t_s_rbtn		*rnode;

	if (!(node = find_node(key, tree->order_foo, tree->anchor)))
		return (RBT_KEY_NOT_FOUND);
	rnode = get_replacement(node);
}
