#include "bin_tree.h"

t_bin_tree *bin_tree_new (void *data)
{
	t_bin_tree *node = (t_bin_tree*)malloc(sizeof(t_bin_tree));

	if (! node) return NULL;

	node->data = data;
	node->root = NULL;
	node->left = NULL;
	node->right = NULL;

	return node;
}

t_bin_tree *bin_tree_ins (void *data, t_bin_tree *tree,
				(int)(*cmp)(void*, void*))
{
	return bin_tree_ins_node(bin_tree_new(data), tree, cmp);
}

t_bin_tree *bin_tree_search (void *data, t_bin_tree *tree,
				(int)(*cmp)(void*, void*))
{
	t_bin_tree *pom=tree;
	int i;

	if (! data || ! cmp) return NULL;

	while (pom) {
		i = (*cmp)(data, pom->data);

		if (i == -1)
			pom = pom->left;
		else if (i == 1)
			pom = pom->right;
		else
			return pom;
	}

	return NULL;
}

t_bin_tree *bin_tree_ins_node (t_bin_tree *node, t_bin_tree *tree,
				(int)(*cmp)(void*, void*))
{
	t_bin_tree *pom=tree;
	
	if (! node || ! tree || ! cmp) return NULL;

	while (1) {
		
		if ((*cmp)(node->data, pom->data) == -1) {
			if (! pom->left) {
				pom->left = node;
				node->root = pom;
				return node;
			} else
				pom = pom->left;
		} else {
			if (! pom->right) {
				pom->right = node;
				node->root = pom;
				return node;
			} else
				pom = pom->right;
		}
	}

	return node;
}

t_bin_tree *bin_tree_rem_node (t_bin_tree *node)
{
	t_bin_tree *pom=NULL;

	if (! node) return NULL;

	/* if no nodes are in left then new node will be in right*/
	if (! node->left) {
		pom = node->right;
	} else if (! node->right)
	/* else new node is maybe in left */
		pom = node->left;
	else {
	/* else exists both left and right subtrees. */
	/* so new node will be the rightmost node in left tree */
		/* seach for rightmost in left subtree */
		pom = node->left;
		while (pom->right)
			pom = pom->right;
		
		/* remove rightmost */
		if (pom->left)
			pom->left->root = pom->root;
		if (pom->root->left == pom)
			pom->root->left = pom->left;
		else
			pom->root->right = pom->left;

		/* rightmost will be new node */
		pom->left = node->left;
		pom->right = node->right;
	}

	/* set pint new node to origin root and root to new node */
	if (pom)
		pom->root = node->root;
	if (node->root) {
		if (node->root->left == node)
			node->root->left = pom;
		else
			node->root->right = pom;
	}

	/* make old node alon */
	node->left = NULL;
	node->right = NULL;
	node->root = NULL;

	return node;
}

void bin_tree_del_node (t_bin_tree *node,
				(void)(*bin_tree_free)(void*))
{
	if (! node || ! bin_tree_free) return;

	bin_tree_rem_node(node);

	if (node->data)
		(*bin_tree_free)(node->data);
	
	free(node);
}
