#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: A pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *temp, *temp_p;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}

	pivot = tree->left;
	temp = pivot->right;

	pivot->right = tree;
	tree->left = temp;

	if (temp != NULL)
	{
		temp->parent = tree;
	}

	temp_p = tree->parent;
	tree->parent = pivot;
	pivot->parent = temp_p;

	if (temp_p != NULL)
	{
		if (temp_p->right == tree)
		{
			temp_p->right = pivot;
		}
		else
		{
			temp_p->left = pivot;
		}
	}

	return (pivot);
}
