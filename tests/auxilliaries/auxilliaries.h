#ifndef AUXILLIARIES_H
# define AUXILLIARIES_H

# include "inner.h"

# define RED_VIOLATION 1
# define BLACK_VIOLATION 2

int
	uniform_depth(
		t_s_rbt *tree, int *ret_depth);

t_e_comp
	int_order(
		void *a, void *b);

int
	print_int_tree(
		t_s_rbt *tree);

int
	print_tree(
		t_s_rbt *tree);

#endif
