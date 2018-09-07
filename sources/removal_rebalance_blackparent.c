#include "inner.h"

/*
** p0 : current weighted node
** p1 : father
** p2 : brother
** p3 : nephews
*/

static void			no_red(
	t_s_rbtn	*p1,
	t_s_rbtn	*p2)
{
	p2->attr |= RED;
}

static void			inner_red_nephew(
	t_s_rbtn	*p1,
	t_s_rbtn	*p2,
	t_s_rbtn	*p3,
	int	left)
{
	p3->attr &= ~RED;
	rotate(!left, p2);
	rotate(left, p1);
}

static void			outer_red_nephew(
	t_s_rbtn	*p1,
	t_s_rbtn	*p3,
	int			left)
{
	p3->attr &= ~RED;
	rotate(left, p1);
}

static void			*red_sibling(
	t_s_rbtn	*p0,
	t_s_rbtn	*p1,
	t_s_rbtn	*p2,
	int			left)
{
	p2->attr &= ~RED;
	p1->attr |= RED;
	rotate(left, p1);
}

t_s_rbtn			*rem_reb_blk(
	t_s_rbtn	*p0,
	t_s_rbtn	*p1,
	t_s_rbtn	*p2,
	int			left)
{
	t_s_rbtn	*p3;

	if (p2->attr & RED)
	{
		red_sibling(p0, p1, p2, left);
		return (p0);
	}
	else if ((p3 = p2->kin[left ? e_right : e_left]) &&
		p3->attr & RED)
		outer_red_nephew(p1, p3, left);
	else if ((p3 = p2->kin[left ? e_left : e_right]) &&
		p3->attr & RED)
		inner_red_nephew(p1, p2, p3, left);
	else
	{
		no_red(p1, p2);
		return (p1);
	}
	return (0);
}
