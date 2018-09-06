#include "inner.h"

static
int
	insert(
		t_s_rbtn *this, t_rbt_ordering with, t_s_rbtn **in)
{
	t_e_comp	cmp;
	int			r;

	if (!*in)
	{
		*in = this;
		insert_rebalance(this);
		return (RBT_SUCCESS);
	}
	if ((cmp = (*with)(this->key, (*in)->key)) == e_eq)
		return (RBT_DUP_KEY);
	else if (cmp == e_lt)
		this->attr |= LEFT;
	else
		this->attr &= ~LEFT;
	this->kin[e_parent] = *in;
	r = insert(this, with, &((*in)->kin[cmp == e_lt ? e_left : e_right]));
	return (r);
}

int
	rbtn_insert(
		void *datum, void *key, void *p_tree)
{
	t_s_rbt * const	tree = (t_s_rbt*)p_tree;
	t_s_rbtn		*new;
	int				r;

	if (!key || !p_tree)
		return (RBT_BAD_ARG);
	if ((new = malloc(sizeof(t_s_rbtn))) &&
		(new->key = malloc(tree->key_sz)))
	{
		ft_memcpy(new->key, key, tree->key_sz);
		new->attr = RED;
		ft_bzero(new->kin, sizeof(new->kin));
		new->datum = datum;
		if ((r = (insert(new, tree->order, &tree->anchor) == RBT_DUP_KEY)))
			del_node(tree->key_sz, new);
		return (r);
	}
	else if (new)
		free(new);
	return (RBT_SYS_ERR);
}
