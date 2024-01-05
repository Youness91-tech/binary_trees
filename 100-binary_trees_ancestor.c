#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *first_node, *second_node;
	binary_tree_t *first_node_p, *second_node_p;

	first_node = first;
	second_node = second;

	if (!first_node || !second_node)
		return (NULL);

	if (first_node == second_node)
		return ((binary_tree_t *)first_node);

	first_node_p = first_node->parent;
	second_node_p = second_node->parent;

	if (first_node == second_node_p ||
		!first_node_p ||
		(!first_node_p->parent && second_node_p))
		return (binary_trees_ancestor(first_node, second_node_p));
	else if (first_node_p == second_node ||
		!second_node_p ||
		(!second_node_p->parent && first_node_p))
		return (binary_trees_ancestor(first_node_p, second_node));

	return (binary_trees_ancestor(first_node_p, second_node_p));
}
