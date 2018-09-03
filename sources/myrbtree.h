#ifndef MYRBTREE_H
# define MYRBTREE_H

# include <stddef.h>

typedef
enum		e_compare {
	e_lt,
	e_eq,
	e_gt
}			t_e_comp;

/*key comparison type*/
/*compare first arg to second arg*/
typedef
t_e_comp
	(*t_ordering)(
		*void, *void);

typedef
int
	(*const t_applythis)(
		void*);

/*functions*/
int
	rbt_apply_inord(
		t_applythis foo, void *p_tree);

int
	rbt_apply_preord(
		t_applythis foo, void *p_tree);

int
	rbt_apply_prerevord(
		t_applythis foo, void *p_tree);

int
	rbt_apply_pstord(
		t_applythis foo, void *p_tree);

int
	rbt_apply_pstrevord(
		t_applythis foo, void *p_tree);

int
	rbt_apply_revord(
		t_applythis foo, void *p_tree);

void
	rbt_delete(
		void **p_tree);	

int
	rbt_delete_apply_ino(
		t_applythis foo, void **p_tree);

void
	rbt_delete_free(
		size_t datum_sz, void **p_tree);

int
	rbt_init(
		t_ordering foo, size_t key_sz,
		void* *pp_tree);

int
	rbtn_insert(
		void *datum, void *key, void *p_tree);

int
	rbtn_remove(
		void *key, void *p_tree);

int
	rbtn_remove_retrieve(
		void *key, t_applythis foo,
		void *p_tree, void *ret_p_datum);

int
	rbtn_remove_free(
		void *key, void *p_tree);

int
	rbtn_retrieve(
		void *key, void *p_tree, void *ret_p_datum);

/*return codes*/
# define RBT_SYS_ERR -1
# define RBT_SUCCESS 0
# define RBT_BAD_ARG 1
# define RBT_DUP_KEY 2

#endif