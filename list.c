#include <stdlib.h>

#include "list.h"

t_lst *lst_new(void)
{
	t_lst *lst = (t_lst *)malloc(sizeof(t_lst));
	
	if (!lst) return NULL;
	
	lst->first = NULL;
	lst->last = NULL;
	
	return lst;
}

t_itm *lst_add(t_lst *lst, void *data)
{
	t_itm *pom = (t_itm *)malloc(sizeof(t_itm));
		
	if (!pom) return NULL;
	if (!lst) {free(pom); return NULL;}

	pom->prev = lst->last;
	pom->data = data;
	pom->next = NULL;

	if (lst->last)
		lst->last->next = pom;
	else
		lst->first = pom;

	lst->last = pom;

	return lst->last;
}

t_itm *lst_push(t_lst *lst, void *data)
{
	t_itm *pom = (t_itm *)malloc(sizeof(t_itm));

	if (!pom) return NULL;
	if (!lst) {free(pom); return NULL;}

	pom->prev = NULL;
	pom->data = data;
	pom->next = lst->first;

	if (lst->first)
		lst->first->prev = pom;
	else
		lst->last = pom;

	return lst->first = pom;
}

t_itm *lst_insert(t_lst *lst, t_itm *itm, void *data)
{
	t_itm *pom;

	if (!lst) return (t_itm *)0;

	if (!lst->first || !itm) return lst_add(lst, data);
	if (!itm->prev) return lst_push(lst, data);
/*	if (!itm->next) return lst_add(lst, data);*/

	pom = (t_itm *)malloc(sizeof(t_itm));
	if (!pom)
		return (t_itm *)0;
	
	pom->prev = itm->prev;
	pom->data = data;
	pom->next = itm;
	itm->prev->next = pom;

	return itm->prev = pom;
}

void *lst_rem(t_lst *lst)
{
	void *pom;
	t_itm *it;

	if (!lst || !lst->last) return NULL;

	pom = lst->last->data;
	it = lst->last;
	if (it->prev)
		it->prev->next = NULL;
	else
		lst->first=NULL;
	lst->last = it->prev;
	free(it);

	return pom;
}

void *lst_pop(t_lst *lst)
{
	void *pom;
	t_itm *it;

	if (!lst || !lst->first) return NULL;

	it = lst->first;
	pom = it->data;
	if (it->next)
		it->next->prev = NULL;
	else
		lst->last = NULL;
	lst->first = it->next;
	free(it);

	return pom;
}

void *lst_cut(t_lst *lst, t_itm *itm)
{
	void *pom;

	if (!itm) return NULL;

	if (!itm->prev)
		return lst_pop(lst);
	if (!itm->next)
		return lst_rem(lst);

	itm->prev->next = itm->next;
	itm->next->prev = itm->prev;
	pom = itm->data;
	
	free(itm);

	return pom;
}


void lst_clean(t_lst *lst, void (*my_free)(void*))
{
	void *buf;
	
	if (!lst) return;
	if (!my_free) return;

	while (lst->first) {
		buf = lst_pop(lst);
		if (buf) (void)(*my_free)(buf);
	}
}
