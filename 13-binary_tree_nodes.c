#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of nodes
 *
 * Return: If tree is NULL, the function must return 0
 * else return node count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_s = 0, right_s = 0, nodes = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		left_s = binary_tree_nodes(tree->left);
		right_s = binary_tree_nodes(tree->right);
		nodes = left_s + right_s;
		return ((tree->left || tree->right) ? nodes + 1 : nodes + 0);
	}
}
