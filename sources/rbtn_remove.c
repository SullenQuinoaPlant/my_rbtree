/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtn_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 07:51:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/09/07 08:00:15 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inner.h"

int					rbtn_remove(
	void *key,
	void *p_tree)
{
	return (remove_node(key, (t_s_apack*)0, p_tree, (void**)0));
}

int					rbtn_remove_apply(
	void *key,
	t_rbt_applyee foo,
	void *foo_arg,
	void *p_tree)
{
	t_s_apack	foo_pkg;

	foo_pkg.f = foo;
	foo_pkg.arg = foo_arg;
	return (remove_node(key, &foo_pkg, p_tree, (void**)0));
}

int					rbtn_remove_retrieve(
	void *key,
	void *p_tree,
	void **ret_p_datum)
{
	return (remove_node(key, (t_s_apack*)0, p_tree, ret_p_datum));
}

static int			here_free(
	void *p_arg,
	void *p_key,
	void **p_datum)
{
	(void)p_arg;
	(void)p_key;
	free(*p_datum);
	return (RBT_SUCCESS);
}

int					rbtn_remove_free(
	void *key,
	void *p_tree)
{
	t_s_apack	foo_pkg;

	foo_pkg.f = here_free;
	foo_pkg.arg = 0;
	
	return (remove_node(key, &foo_pkg, p_tree, (void**)0));
}
