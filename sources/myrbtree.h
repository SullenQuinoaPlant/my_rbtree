#ifndef MYRBTREE_H
# define MYRBTREE_H

# include <stddef.h>

int
	rbt_apply_inord(
		int (*foo)(void*), void *p_tree);

int
	rbt_apply_preord(
		int (*foo)(void*), void *p_tree);

int
	rbt_apply_prerevord(
		int (*foo)(void*), void *p_tree);

int
	rbt_apply_pstord(
		int (*foo)(void*), void *p_tree);

int
	rbt_apply_pstrevord(
		int (*foo)(void*), void *p_tree);

int
	rbt_apply_revord(
		int (*foo)(void*), void *p_tree);

void
	rbt_delete(
		void *p_tree);	

int
	rbt_delete_apply_ino(
		int (*foo)(void*), void *p_tree);

void
	rbt_delete_free(
		size_t datum_sz, void *p_tree);

void
	rbt_init(
		t_ordering foo, size_t key_sz,
		void *p_tree);

int
	rbtn_insert(
		void *datum, void *key, void *p_tree);

int
	rbtn_remove(
		void *key, void *p_tree);

int
	rbtn_remove_retrieve(
		void *key, , int (*foo)(void*),
		void *p_tree, void *ret_p_datum);

int
	rbtn_remove_free(
		void *key, void *p_tree);

int
	rbtn_retrieve(
		void *key, void *p_tree, void *ret_p_datum);

#endif
