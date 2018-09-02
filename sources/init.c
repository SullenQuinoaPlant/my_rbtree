#include "inner.h"

void
	rbt_init(
		t_ordering foo, size_t key_sz,
		t_s_rbt *ret)
{
	t_s_rbt	init;

	init.order_foo = foo;
	init.key_sz = key_sz;
	init.anchor = 0;
	*ret = init;
}
