#include <stdio.h>
#include "aux_inner.h"

int				addr_tree_printer(
	void *a,
	void *k,
	void **pd)
{
	void	*p;

	(void)a;
	p = *(void**)k;
	printf("k : %p, converted k : %p, datum :%p\n",
		k, p, *pd);
}
