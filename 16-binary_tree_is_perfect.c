#include "binary_trees.h"

size_t tree_depth(const binary_tree_t *tree);
unsigned char is_leaff(const binary_tree_t *node);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
const binary_tree_t *get_leaff(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaff - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 */
unsigned char is_leaff(const binary_tree_t *node)
{
	return ((node->right == NULL && node->left == NULL) ? 1 : 0);
}

/**
 * tree_depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 */
size_t tree_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + tree_depth(tree->parent) : 0);
}

/**
 * get_leaff - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaff(const binary_tree_t *tree)
{
	if (is_leaff(tree) == 1)
		return (tree);
	return (tree->left ? get_leaff(tree->left) : get_leaff(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaff(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->right == NULL || tree->left == NULL)
		{
		return (0);
		}
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		{
		return (0);
		}
	return (is_perfect_recursive(tree, tree_depth(get_leaff(tree)), 0));
}
