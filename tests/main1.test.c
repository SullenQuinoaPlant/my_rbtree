#define SZ0 10

#include <stdio.h>
#include <stdint.h>
#include "libaux.h"

int
	wtf(
		void *arg,
		void *key,
		void **datum)
{
	int		i;
	void	**ar;
	void	*const stored_key = *(void**)key;

	ar = *(void***)arg;
	for (i = 0; i < SZ0; i++)
		if (*(ar + i) == stored_key)
			break;
	if (i == SZ0)
		printf("found erroneous value in tree : %p\n",
			stored_key);
	return (0);
}

int
	count_nodes(
		void *node_count,
		void *key,
		void **datum)
{
	(*(int*)node_count)++;
	(void)key;
	(void)datum;
}


int		main()
{
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
	int		node_count;

	if ((rbt_init(addr_order, sizeof(void*), (void**)&p)))
		return (1);
	printf("inserting in tree\n");
	for (i = 0; i < SZ0; i++)
	{
		rbtn_insert(0, &addr_ar[i], (void**)p);
		node_count = 0;
		rbt_apply_inord(count_nodes, (void*)&node_count, p);
		printf("node_count is now : %d\n", node_count);
	}
	printf("checking tree\n");
	rbt_apply_inord(wtf, &addr_ar, p);
	node_count = 0;
	rbt_apply_inord(count_nodes, (void*)&node_count, p);
	printf("removing from tree\n");
	for (i = 0; i < SZ0; i++)
	{
		rbtn_remove(&addr_ar[i], (void**)p);
		node_count = 0;
		rbt_apply_inord(count_nodes, (void*)&node_count, p);
		printf("node_count is now : %d\n", node_count);
		rbt_apply_inord(wtf, &addr_ar, p);
	}
	rbt_delete((void**)&p);
	return (0);
}
