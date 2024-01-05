#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: A pointer to the root node of the tree to measure the balance factor
 *
 * Return: If tree is NULL, return 0, else return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_b, right_b;

	if (tree ==  NULL)
		return (0);

	else
	{
		left_b = binary_tree_height_bl(tree->left);
		right_b = binary_tree_height_bl(tree->right);
		return (left_b - right_b);
	}
}

/**
 * binary_tree_height_bl - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: If tree is NULL, your function must return 0
 * else return height.
 */
size_t binary_tree_height_bl(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0;

	if (tree)
	{
		left_s = tree->left ? 1 + binary_tree_height_bl(tree->left) : 1;
		right_s = tree->right ? 1 + binary_tree_height_bl(tree->right) : 1;
		return ((left_s > right_s) ? left_s : right_s);
	}
	return (0);
}
