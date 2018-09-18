#include "libaux.h"

#define INC1 10
int		main()
{
	int		i;
	int		ret;
	t_s_rbt	*p;
	int		tree_depth;
	t_list	*inserted;

	if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
		for (i = 0; i < INC1; i++)
		{
			ft_lstadd(&inserted, ft_lstnew(&i, sizeof(int)));
			rbtn_insert(inserted->content, &i, p);
			print_int_tree(p);
		}
	print_tree(p);
	ft_lstdel(&inserted, 0);
	ret = uniform_depth(p, &tree_depth);
	rbt_delete((void**)&p);
	return (0);
}
