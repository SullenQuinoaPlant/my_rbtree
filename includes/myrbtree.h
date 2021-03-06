/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myrbtree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 06:36:09 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:10:18 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYRBTREE_H
# define MYRBTREE_H

# include <stddef.h>

typedef void	*t_rbtree;

typedef enum e_compare					t_e_comp;
enum									e_compare {
	e_lt,
	e_eq,
	e_gt
};

/*
**key comparison type
**compare first arg to second arg
*/
typedef t_e_comp						(*t_rbt_ordering)(
	void *a,
	void *b);

typedef int								(*t_rbt_applyee)(
	void *arg,
	void *key,
	void **p_datum);

/*
**functions
*/
int										rbt_apply_inord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbt_apply_preord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbt_apply_prerevord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbt_apply_pstord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbt_apply_pstrevord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbt_apply_revord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

void									rbt_delete(
	void			**p_tree);

int										rbt_delete_apply_postord(
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			**p_tree);

void									rbt_delete_free(
	size_t			datum_sz,
	void			**p_tree);

int										rbt_init(
	t_rbt_ordering	foo,
	size_t			key_sz,
	void			**pp_tree);

int										rbtn_insert(
	void			*datum,
	void			*key,
	void			*p_tree);

int										rbtn_remove(
	void			*key,
	void			*p_tree);

int										rbtn_remove_apply(
	void			*key,
	t_rbt_applyee	foo,
	void			*foo_arg,
	void			*p_tree);

int										rbtn_remove_retrieve(
	void			*key,
	void			*p_tree,
	void			**ret_p_datum);

int										rbtn_remove_free(
	void			*key,
	void			*p_tree);

int										rbtn_retrieve(
	void			*key,
	void			*p_tree,
	void			**ret_p_datum);

/*
**return codes
*/
# define RBT_SYS_ERR -1
# define RBT_SUCCESS 0
# define RBT_BAD_ARG 1
# define RBT_DUP_KEY 2
# define RBT_KEY_NOT_FOUND 3

#endif
