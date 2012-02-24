#ifndef __LIST_H__
#define __LIST_H__

#define LST_FREE(fn) (void (*)(void*))(fn)

typedef struct s_itm {
	struct s_itm *prev;
	void *data;
	struct s_itm *next;
} t_itm;

typedef struct s_lst {
	t_itm *first;
	t_itm *last;
} t_lst;

/* create new list*/
extern t_lst *lst_new(void);

/* add item to end of list */
extern t_itm *lst_add(t_lst *lst, void *data);

/* add item at begining of list */
extern t_itm *lst_push(t_lst *lst, void *data);

/* insert data before itm */
extern t_itm *lst_insert(t_lst *lst, t_itm *itm, void *data);

/* remove item from end of list */
extern void *lst_rem(t_lst *lst);

/* remove item from top of list */
extern void *lst_pop(t_lst *lst);

/* cut off item */
extern void *lst_cut(t_lst *lst, t_itm *itm);

/* clear all list by user defined free function for data */
extern void lst_clean(t_lst *lst, void (*my_free)(void*));

#endif
