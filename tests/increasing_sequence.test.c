#define HOW_MANY_TESTS 100
#include "cmocka/my_overlay.h"

#include "auxilliaries.h"

int	declare_tests_and_run(int all_of, char *these[])
{
	#define INC1 10000
	T(increasing_sequence,
		int		i;
		t_s_rbt	*p;

		if (rbt_init(int_order, sizeof(int), (void**)&p))
			for (i = 0; i < INC1; i++)
				rbtn_insert(0, &i, p);
		assert_true(uniform_depth);
	)

	return(run_test_arr(all_of, these));
}
