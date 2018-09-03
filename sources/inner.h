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

/*node attribute flags:*/
# define RED 0X01
# define LEFT 0X02

typedef
enum		e_kin_nodes {
	e_parent,
	e_left,
	e_right,
	e_tekns_sz
}			t_e_kns;

typedef
struct		s_rbtree_node {
	void		*key;
	int			attributes;
	t_s_rbtn	kin[e_tekns_sz];
	void		*datum;
}			t_s_rbtn;

typedef
struct		s_red_black_tree {
	t_ordering	order_foo;
	size_t		key_sz;
	t_s_rbtn	*anchor;
}			t_s_rbt;

void
	del_node(
		t_s_rbtn *node);
#endif