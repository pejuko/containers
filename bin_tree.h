/*
 * Search Binary Tree File
 */

#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef struct {
	void *data;
	t_bin_tree *root;	/* parent node */
	t_bin_tree *left;	/* left subtree */
	t_bin_tree *right;	/* right subtree */
} t_bin_tree;


/*
 * create new binary tree
 */
extern t_bin_tree *bin_tree_new (void *data);

/*
 * search for data in binary tree
 */
extern t_bin_tree *bin_tree_search (void *data, t_bin_tree *tree,
				(int)(*cmp)(void*, void*))

/*
 * insert data to tree use cmp compare function which return:
 * -1 if arg1  < arg2
 *  0 if arg1 == arg2
 *  1 if arg1  > arg2
 */
extern t_bin_tree *bin_tree_ins (void *data, t_bin_tree *tree,
				(int)(*cmp)(void*, void*));

/*
 * insert node to the tree
 */
extern t_bin_tree *bin_tree_ins_node (t_bin_tree *node, t_bin_tree *tree,
				(int)(*cmp)(void*, void*));

/*
 * remove given node from bin tree
 * !!! its remove _all_ subtree !!! -- node will be root :-)
 */
extern t_bin_tree *bin_tree_rem_node (t_bin_tree *node);

/*
 * delete given node and data will be freed by bin_tree_free
 */
extern void bin_tree_del_node (t_bin_tree *node,
					(void)(*bin_tree_free)(void*));

/*
 * delete bin_tree, data will be freed by bin_tree free
 */
extern void bin_tree_del (t_bin_tree *tree, (void)(*bin_tree_free)(void*));

#endif
