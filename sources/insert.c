#include "inner.h"

static
int
	insert(
		t_s_rbtn *this, t_ordering with, t_s_rbtn **in)
{
	t_e_comp	cmp;

	if (!*in)
		return (insert_rebalance((*in = this)));
	if ((cmp = (*with)(this->key, (*in)->key)) == e_eq)
		return (RBT_DUP_KEY);
	else if (cmp == e_lt)
		this->attr |= LEFT;
	else
		this->attr &= ~LEFT;
	this->kin[e_parent] = *in;
	return (insert(this, with, &in->kin[cmp == e_lt ? e_left : e_right]));
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
		if (r = (insert(new, &tree->anchor) == RBT_DUP_KEY))
			del_node(new);
		return (r);
	}
	else if (new)
		free(new);
	return (RBT_SYS_ERR);
}
