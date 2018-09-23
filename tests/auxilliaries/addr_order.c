#include <stdint.h>
#include "aux_inner.h"

t_e_comp
	addr_order(
		void *a,
		void *b)
{
	void *ka;
	void *kb;

	ka = *(void**)a;
	kb = *(void**)b;
	if (ka == kb)
		return (e_eq);
	else if ((uintptr_t)ka < (uintptr_t)kb)
		return (e_lt);
	return (e_gt);
}
