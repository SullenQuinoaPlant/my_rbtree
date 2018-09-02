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
enum		e_child_nodes {
	e_left,
	e_right,
	e_tecns_sz
}			t_e_cns;

typedef
struct		s_rbtree_node {
	void		*key;
	void		*datum;
	t_e_col		color;
	t_s_rbtn	kinder[e_tecns_sz];
}			t_s_rbtn;

typedef
struct		s_red_black_tree {
	t_ordering	order_foo;
	size_t		key_sz;
	t_s_rbtn	*anchor;
}			t_s_rbt;

#endif
