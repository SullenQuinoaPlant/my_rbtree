#ifndef MYRBTREE_H
# define MYRBTREE_H

typedef
enum		e_compare {
	e_lt,
	e_eq,
	e_gt
}			t_e_comp;

typedef
t_e_comp
	(*t_ordering)(
		*void, *void);

typedef
enum		e_color {
	e_red,
	e_black
}			t_e_col;

typedef
struct		s_rbtree_node {
	void		*key;
	void		*data;
	t_e_col		color;
}			t_s_rbtn;

typedef
struct		s_red_black_tree {
	t_ordering	order_foo;
	size_t		key_sz;
	t_s_rbtn	stem;
}			t_s_rbt;

int
	rbt_apply(
		int (*foo)(void*), t_s_rbt *tree);

void
	rbt_delete(
		t_s_rbt *tree);	

int
	rbt_delete_apply(
		int (*foo)(void*), t_s_rbt *tree);

void
	rbt_delete_free(
		t_s_rbt *tree);

void
	rbt_init(
		t_ordering, t_s_rbt *tree);

int
	rbtn_apply(
		int (*foo)(void*), void *key, t_s_rbt *tree);

int
	rbtn_insert(
		void *data, void *key, t_s_rbt *tree);

int
	rbtn_remove(
		void *key, t_s_rbt *tree);

int
	rbtn_remove_apply(
		void *key, , int (*foo)(void*), t_s_rbt *tree);

int
	rbtn_remove_free(
		void *key, t_s_rbt *tree);

#endif
