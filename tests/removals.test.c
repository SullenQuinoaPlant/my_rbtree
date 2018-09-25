#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libmystupidmath.h"
#include "libaux.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	int		tree_depth;

	#define SZ0 10
	T(static_array,
		void	**addr_ar;
			addr_ar = ((void*[SZ0]){
				(void*)0x9051020,
				(void*)0x9051478,
				(void*)0x90514c8,
				(void*)0x9051518,
				(void*)0x9051568,
				(void*)0x90515b8,
				(void*)0x9051608,
				(void*)0x9051658,
				(void*)0x90516a8,
				(void*)0x90516f8
			});
		int		i;
		t_s_rbt	*p;
	
		if ((rbt_init(addr_order, sizeof(void*), (void**)&p)))
			skip();
		for (i = 0; i < SZ0; i++)
			rbtn_insert(0, &addr_ar[i], (void**)p);
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth <= my_flog2(SZ0));
		rbt_delete((void**)&p);
	)

	T(static_int_array_and_remove,
		void	*int_ar;
			int_ar = ((int[SZ0]){
				0x9051020,
				0x9051478,
				0x90514c8,
				0x9051518,
				0x9051568,
				0x90515b8,
				0x9051608,
				0x9051658,
				0x90516a8,
				0x90516f8
			});
		int		i;
		t_s_rbt	*p;
	
		if ((rbt_init(int_order, sizeof(void*), (void**)&p)))
			skip();
		for (i = 0; i < SZ0; i++)
			rbtn_insert(0, &int_ar[i], (void**)p);
		for (i = 0; i < SZ0; i++)
		{
			rbtn_remove(&int_ar[i], (void**)p);
			assert_false(uniform_depth(p, &tree_depth));
			assert_true(tree_depth <= my_flog2(SZ0));
		}
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth == 0);
		rbt_delete((void**)&p);
	)

	T(static_array_and_remove,
		void	**addr_ar;
			addr_ar = ((void*[SZ0]){
				(void*)0x9051020,
				(void*)0x9051478,
				(void*)0x90514c8,
				(void*)0x9051518,
				(void*)0x9051568,
				(void*)0x90515b8,
				(void*)0x9051608,
				(void*)0x9051658,
				(void*)0x90516a8,
				(void*)0x90516f8
			});
		int		i;
		t_s_rbt	*p;
	
		if ((rbt_init(addr_order, sizeof(void*), (void**)&p)))
			skip();
		for (i = 0; i < SZ0; i++)
			rbtn_insert(0, &addr_ar[i], (void**)p);
		for (i = 0; i < SZ0; i++)
		{
			rbtn_remove(&addr_ar[i], (void**)p);
			assert_false(uniform_depth(p, &tree_depth));
			assert_true(tree_depth <= my_flog2(SZ0));
		}
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth == 0);
		rbt_delete((void**)&p);
	)

	#define SZ1 10
	T(malloced10,
		int		i;
		t_s_rbt	*p;
		void*	ar[SZ1];

		if (!(rbt_init(addr_order, sizeof(void*), (void**)&p)))
			for (i = 0; i < SZ1; i++)
				if ((ar[i] = malloc(1)))
					rbtn_insert(0, &ar[i], p);
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth <= my_flog2(SZ1));
		rbt_delete((void**)&p);
		for (i = 0; i < SZ1; i++)
			if (ar[i])
				free(ar[i]);
	)

	#define SZ2 10000
	T(malloced10000,
		int		i;
		t_s_rbt	*p;
		void*	ar[SZ2];

		if (!(rbt_init(addr_order, sizeof(void*), (void**)&p)))
			for (i = 0; i < SZ2; i++)
				if ((ar[i] = malloc(1)))
					rbtn_insert(0, &ar[i], p);
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth <= my_flog2(SZ2));
		rbt_delete((void**)&p);
		for (i = 0; i < SZ2; i++)
			if (ar[i])
				free(ar[i]);
	)

	return(run_test_arr(all_of, these));
}
