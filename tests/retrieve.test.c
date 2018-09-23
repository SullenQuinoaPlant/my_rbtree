#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libaux.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	int		tree_depth;

	#define INC1 10000
	T(retrieve_pointer_copies,
		int		i;
		t_s_rbt	*p;
		void	*ret;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
		{
			for (i = 0; i < INC1; i++)
				rbtn_insert(&i, &i, p);
			for (i = 0; i < INC1; i++)
			{
				rbtn_retrieve(&i, p, &ret);
				assert_true(*(int*)ret == i);
			}
			rbt_delete((void**)&p);
		}
		else
			skip();
	)

	#define INC2 20
	T(retrieve_static_addresses,
		int		i;
		int		ar[INC2];
		t_s_rbt	*p;
		void	*ret;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
		{
			for (i = 0; i < INC2; i++)
			{
				rbtn_insert(ar + i, &i, p);
				ar[i] = i;
			}
			for (i = 0; i < INC2; i++)
			{
				rbtn_retrieve(&i, p, &ret);
				assert_true(*(int*)ret == i);
			}
			rbt_delete((void**)&p);
		}
		else
			skip();
	)

	T(retrieve_allocated_addresses,
		int		i;
		void	*ar[INC2];
		t_s_rbt	*p;
		void	*ret;

		if (!(rbt_init(addr_order, sizeof(void*), (void**)&p)))
		{
			for (i = 0; i < INC2; i++)
			{
				if ((ar[i] = malloc(sizeof(int))))
				{
					*(int*)ar[i] = i;
					rbtn_insert(ar[i], ar + i, p);
				}
			}
			printf("printing tree; \n");
			rbt_apply_inord(&addr_tree_printer, (void*)0, p);
			for (i = 0; i < INC2; i++)
			{
				if (ar[i])
				{
					rbtn_retrieve(&ar[i], (void*)p, &ret);
					assert_true(*(int*)ret == i);
				}
			}
			rbt_delete((void**)&p);
		}
		else
			skip();
	)

	return(run_test_arr(all_of, these));
}
