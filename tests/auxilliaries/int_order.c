#include "aux_inner.h"

t_e_comp
	int_order(
		void *a, void *b)
{
	int		res;

	res = *(int*)a - *(int*)b;
	if (res < 0)
		return (e_lt);
	else if (res > 0)
		return (e_gt);
	return (e_eq);
}
