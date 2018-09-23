#include <stdio.h>
#include "aux_inner.h"

int			print(
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
