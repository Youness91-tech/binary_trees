#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: A pointer to the node to check
 * Return: INT -> 1 or 0
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_s, right_s;

	if (tree == NULL)
		return (0);

	left_s = binary_tree_height(tree->left);
	right_s = binary_tree_height(tree->right);

	if (left_s >= right_s)
		return (1 + left_s);

	return (1 + right_s);
}

/**
 * check_if_perfect - Checks if the tree is perfect
 * @tree: Tree that will be checked
 * Return: 0 or the size of a tree
 */
int check_if_perfect(const binary_tree_t *tree)
{
	int left_s = 0, right_s = 0;

	if (tree == NULL)
		return (1);

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
 * @tree: Tree that will be checked
 * Return: 1 or 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int output = 0;

	if (tree == NULL)
	{
		return (1);
	}
	else
	{
		output = check_if_perfect(tree);
		if (output != 0)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A Pointer to the root node of the tree to check
 * Return: (INT) -> 1 or 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *left_node, *right_node;

	size_t left_node_height;
	size_t right_node_height;

	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	left_node = tree->left;
	right_node = tree->right;
	left_node_height = binary_tree_height(left_node);
	right_node_height = binary_tree_height(right_node);

	if (left_node_height == right_node_height)
	{
		if (binary_tree_is_perfect(left_node) &&
			binary_tree_is_complete(right_node))
			return (1);
	}
	else if (left_node_height == right_node_height + 1)
	{
		if (binary_tree_is_complete(left_node) &&
			binary_tree_is_perfect(right_node))
			return (1);
	}

	return (0);
}
