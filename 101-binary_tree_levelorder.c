#include "binary_trees.h"
/**
 * binary_tree_height - takes the height of a binary tree.
 *@tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * print_at_level - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - goes through a binary tree in level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
/* Variables to store the tree height and current level during traversal */
	size_t h = 0, i = 1;

/* Check if the tree and function pointer are valid */
	if (tree && func)
	{
/* Determine the height of the binary tree */
		h = binary_tree_height(tree);
/* Traverse the tree in level-order from level 1 to the tree height + 1 */
		while (i <= h + 1)
		{
/* Call the function for all nodes at the current level */
			print_at_level(tree, func, i);
			i++;
		}
	}

}
