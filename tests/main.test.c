#include "libaux.h"

#define INC1 10
int		main()
{
	int		i;
	int		ret;
	t_s_rbt	*p;

	if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
		for (i = 0; i < INC1; i++)
			rbtn_insert(0, &i, p);
	ret = uniform_depth(p);
	print_tree(p);
	rbt_delete((void**)&p);
	return (0);
}
