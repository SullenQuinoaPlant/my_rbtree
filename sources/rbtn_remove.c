#include "inner.h"

int
	rbtn_remove(
		void *key, void *p_tree)
{
	return (remove(key, p_tree, 0, 0));
}

int
	rbtn_remove_apply(
		void *key, t_rbt_applyee foo, void *p_tree)
{
	return (remove(key, p_tree, foo, 0));
}

int
	rbtn_remove_retrieve(
		void *key, void *p_tree, void *ret_p_datum)
{
	return (remove(key, p_tree, 0, ret_p_datum));
}

static
int
	here_free(
		void *p)
{
	free(p);
	return (RBT_SUCCESS);
}

int
	rbtn_remove_free(
		void *key, void *p_tree)
{
	return (remove(key, p_tree, &here_free, 0));
}
