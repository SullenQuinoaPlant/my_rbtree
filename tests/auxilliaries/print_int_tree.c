#include <stdio.h>
#include "aux_inner.h"

static int		printer(void* p_int) {
	int const*	i = (int*)p_int;

	printf("%d ", *i);
	return (*i);
}

int				print_int_tree(t_s_rbt*p)
{
	int		r;

	printf("\nprinting tree: \n");
	r = rbt_apply_inord(printer, (void*)p);
	return (r);
}
