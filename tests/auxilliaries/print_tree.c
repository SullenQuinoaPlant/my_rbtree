#include <stdio.h>
#include "aux_inner.h"

static
int
	printer(
		void *nope,
		void *nnope,
		void **nnnope)
{
	static int	count;

	(void)nope;
	(void)nnope;
	(void)nnnope;
	printf("%d ", count);
	return (++count);
}

int				print_tree(t_s_rbt*p)
{
	int		r;

	printf("printing tree: \n");
	r = rbt_apply_inord(printer, 0, (void*)p);
	printf("\n");
	return (r);
}
