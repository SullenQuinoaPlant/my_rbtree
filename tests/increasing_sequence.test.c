#define HOW_MANY_TESTS 100
#include <stdio.h>
#include "cmocka/my_overlay.h"

#include "libaux.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	T(nop,
		printf("increasing_sequence_tests\n");
	)

	#define INC1 10000
	T(increasing_sequence,
		int		i;
		t_s_rbt	*p;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
			for (i = 0; i < INC1; i++)
				rbtn_insert(0, &i, p);
		assert_true(uniform_depth(p));
		rbt_delete((void**)&p);
	)

	#define INC2 20
	T(increasing_sequence_print,
		int		i;
		t_s_rbt	*p;

		if (!(rbt_init(int_order, sizeof(int), (void**)&p)))
			for (i = 0; i < INC2; i++)
				rbtn_insert(0, &i, p);
		int	print_tree(void* nope) {
			static int	count;

			(void)nope;
			printf("%d ", count);
			return (count++);
		}
		printf("printing tree: \n");
		rbt_apply_inord(print_tree, (void*)p);
		assert_true(print_tree(0) == INC2);
		assert_true(uniform_depth(p));
		rbt_delete((void**)&p);
	)

	return(run_test_arr(all_of, these));
}
