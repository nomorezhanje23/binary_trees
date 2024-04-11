#include "binary_trees.h"

/**
 * count_leaves - Recursively counts the number of leaves in a binary tree
 * @node: A pointer to a tree node
 * @leaves: A pointer to the variable holding the number of leavees
 */
void count_leaves(const binary_tree_t *node, size_t *leaves)
{
	if (node)
	{
		if (node->left == NULL && node->right == NULL)
		{
			(*leaves)++; /* Increment the leaf count for each leaf node */
		}
		else
		{
			/* Recursively traverse the left and right subtrees */
			count_leaves(node->left, leaves);
			count_leaves(node->right, leaves);
		}
	}
}

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the binary tree
 * Return: The number of leaves in the tree. If 'tree' is NULL, returns 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			count_leaves(tree, &leaves);
		else
			/* If the tree has only one node (root), consider it as a leaf. */
			leaves++;
	}

	return (leaves);
}
