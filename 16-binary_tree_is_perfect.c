#include "binary_trees.h"

/**
 * check_if_perfect - Checks if the tree is perfect
 * @tree: A pointer to the root node of the tree to check
 * Return: 0 or the size of a tree
 */
int check_if_perfect(const binary_tree_t *tree)
{
	int left_s = 0, right_s = 0;

	if (tree->left && tree->right)
	{
		left_s = 1 + check_if_perfect(tree->left);
		right_s = 1 + check_if_perfect(tree->right);
		if (right_s == left_s &&
		right_s != 0 &&
		left_s != 0)
			return (right_s);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_is_perfect - Checks if tree is per or not
 * @tree: A pointer to the root node of the tree to check
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int output = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		output = check_if_perfect(tree);
		if (output != 0)
			return (1);
		return (0);
	}
}
