#include "binary_trees.h"
/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 * Return: leaves number
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0, leaves = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_s = binary_tree_leaves(tree->left);
		right_s = binary_tree_leaves(tree->right);
		leaves = left_s + right_s;
		return ((!left_s && !right_s) ? leaves + 1 : leaves + 0);
	}
}
