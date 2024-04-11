#include "binary_trees.h"

/**
 * is_bst_helper - Helper function for binary_tree_is_bst
 * @node: Node to check
 * @min_val: Minimum value allowed in the subtree rooted at 'node'
 * @max_val: Maximum value allowed in the subtree rooted at 'node'
 * Return: 1 if 'node' is part of a valid binary search tree (BST)
 */
int is_bst_helper(const binary_tree_t *node, int min_val, int max_val)
{
	if (node == NULL)
		return (1);

	/* Check if the value of 'node' is within the valid range */
	if (node->n <= min_val || node->n >= max_val)
		return (0);

	/* Recursively check the left and right subtrees, enforcing constraints */
	return (is_bst_helper(node->left, min_val, node->n) &&
		   is_bst_helper(node->right, node->n, max_val));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST).
 * @tree: Binary tree to check
 * Return: 1 if 'tree' is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Call the helper function with initial minimum and maximum values */
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
