#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp, *temp_p;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	pivot = tree->right;
	temp = pivot->left;

	pivot->left = tree;
	tree->right = temp;

	if (temp != NULL)
	{
		temp->parent = tree;
	}

	temp_p = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp_p;

	if (temp_p != NULL)
	{
		if (temp_p->left == tree)
		{
			temp_p->left = pivot;
		}
		else
		{
			temp_p->right = pivot;
		}
	}

	return (pivot);
}
