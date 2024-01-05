#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_s;
	size_t right_s;

	if (tree == NULL)
		return (0);

	left_s = binary_tree_height(tree->left);
	right_s = binary_tree_height(tree->right);

	if (left_s >= right_s)
		return (1 + left_s);

	return (1 + right_s);
}

/**
 * tree_level_action - Perform a specified action
 *   on all nodes of a binary tree at a given level
 * @tree: A pointer to the root node of the tree
 * @level: The level at which the action should be performed
 * @func: A pointer to a function that takes an integer
 * Return: Nothing
*/

void tree_level_action(const binary_tree_t *tree, size_t level,
	void (*func)(int))
{
	if (tree == NULL)
	{
		return;
	}

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		tree_level_action(tree->left, level - 1, func);
		tree_level_action(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using
 *                          level-order traversal
 * @tree: A pointer to the root node of the tree
 * @func: A pointer to a function that takes an integer
 * Return: nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree,
	void (*func)(int))
{
	size_t tree_height, idx;

	if (tree == NULL || func == NULL)
		return;

	tree_height = binary_tree_height(tree);

	idx = 1;
	while (index <= tree_height)
	{
		tree_level_action(tree, idx, func);
		idx++;
	}
}
