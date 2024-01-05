#include "binary_trees.h"
/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 *         else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0;

	if (tree)
	{
		left_s = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_s = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left_s > right_s) ? left_s : right_s);
	}
	return (0);
}
