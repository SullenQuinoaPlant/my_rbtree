#include "inner.h"

t_s_rbtn
	*find_node(
		void *key, t_rbt_ordering foo,
		t_s_rbtn *at)
{
	t_e_comp	cmp;

	if (!at)
		return (RBT_KEY_NOT_FOUND);
	if ((cmp = (*foo)(key, at->key)) == e_eq)
		return (at);
	return (find_node(key, foo, at->kin[cmp == e_lt ? e_left : e_right]));
}
