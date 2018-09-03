#include "inner.h"

int
	rbt_init(
		t_rbt_ordering foo, size_t key_sz,
		void **p_ret)
{
	t_s_rbt	init;
	t_s_rbt	*alloc;
	int		r;

	if (p_ret)
		*p_ret = 0;
	if (!foo || !kef_sz || !p_ret)
		return (1);
	if (!(alloc = malloc(sizeof(t_s_rbt))))
		return (-1);
	init = (t_s_rbt){foo, key_sz, 0};
	*alloc = init;
	*p_ret = (void*)alloc;
	return (0);
}
