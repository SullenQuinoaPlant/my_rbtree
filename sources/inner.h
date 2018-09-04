#ifndef INNER_H
# define INNER_H 

# include <stdlib.h>

# include "libft.h"
# include "myrbtree.h"

typedef
enum		e_color {
	e_red,
	e_black
}			t_e_col;

typedef
enum		e_kin_nodes {
	e_parent,
	e_left,
	e_right,
	e_tekns_sz
}			t_e_kns;

/*node attribute flags:*/
/*used for (t_s_rbtn).attr*/
# define RED 0X01
# define LEFT 0X02
# define WEIGHT 0X04

typedef
struct		s_rbtree_node {
	void		*key;
	int			attr;
	t_s_rbtn	*kin[e_tekns_sz];
	void		*datum;
}			t_s_rbtn;

typedef
struct		s_red_black_tree {
	t_rbt_ordering	order_foo;
	size_t			key_sz;
	t_s_rbtn		*anchor;
	unsigned int	ticker;
}			t_s_rbt;

void
	del_node(
		t_s_rbtn *node);

t_s_rbtn
	*find_node(
		void *key, t_rbt_ordering foo,
		t_s_rbtn *at);

t_s_rbtn
	*next_ino(
		t_s_rbtn *from);

t_s_rbtn
	*prev_ino(
		t_s_rbtn *from);

void
	rem_reb_red(
		t_s_rbtn *focus, t_s_rbtn *red_parent);

void
	remove_actually(
		t_s_rbtn *removee);

int
	remove_a_node(
		void *at_key, t_rbt_applyee foo,
		void *p_tree, void **ret_p_datum);
		
void
	rotate(
		int left_or_not, t_s_rbtn *at);

void
	rotate_left(
		t_s_rbtn *at);

void
	rotate_right(
		t_s_rbtn *at);

#endif
