#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libaux.h"
#include "libmystupidmath.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	int		tree_depth;

	#define INC1 10000
	T(increasing_sequence,
		int		i;
		t_s_rbt	*p;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
			for (i = 0; i < INC1; i++)
				rbtn_insert(0, &i, p);
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth <= my_flog2(INC1));
		rbt_delete((void**)&p);
	)

	#define INC2 20
	T(increasing_sequence_print,
		int		i;
		t_s_rbt	*p;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
			for (i = 0; i < INC2; i++)
				rbtn_insert(0, &i, p);
		assert_true(print_tree(p) == 0x1f);
		assert_false(uniform_depth(p, &tree_depth));
		assert_true(tree_depth <= my_flog2(INC2));
		rbt_delete((void**)&p);
	)

	return(run_test_arr(all_of, these));
}
