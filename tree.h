#ifndef __TREE_H__
#define __TREE_H__

typedef struct tree {
	struct tree *root;	/* parent node */
	void *data;		/* there are stored data */

	/* list of subtrees */
	struct tree *first;	/* first subtree of this node */
	struct tree *actual;	/* iterator */
	struct tree *last;	/* last subtree of this node */

	struct tree *next;	/* next subtree of parent's node */
	struct tree *prev;	/* previous subtree of parent's node */
} tree;

/*
 * create new node/(sub)tree
 */
extern tree *tree_new(void *data);

/*
 * add subtree data at beginig of node
 * !!! it will first do tree_rem(data) !!!
 */
extern tree *tree_add_first(tree *node, tree *data);

/*
 * create new node (subtree) from data and then
 * tree_add_first(node, new_subtree)
 */
extern tree *tree_push(tree *node, void *data);

/*
 * remove first subtree from node
 */
extern tree *tree_pop(tree *node);

/*
 * remove given subtree from tree
 */
extern tree *tree_rem(tree *item);
/* extern tree *tree_rem_tree(tree *node); */

/*
 * delete all given tree with data freeing
 * by data_free which you must set
 */
extern void tree_del(tree *node);

/*
 * delete all subtree of given node
 * except given node
 */
extern void tree_del_nodes(tree *node);

/*
 * user defined free function for data
 */
extern void (*data_free)(void*);

#endif
