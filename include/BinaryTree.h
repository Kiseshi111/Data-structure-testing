#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

namespace Kiseshi {
	template <typename T>
	class TreeNode {
	public:
		T binaryTreeData;
		TreeNode* left;
		TreeNode* right;

		TreeNode(const T& value) :
			binaryTreeData(value),
			left(nullptr),
			right(nullptr) {}
	};

	template <typename T>
	class BinaryTree {
	private:
		TreeNode<T>* root;

	public:
		BinaryTree() : root(nullptr) {}

		void insert(const T& value) {
			root = insertRecursive(root, value);
		}

		bool search(const T& value) {
			return searchRecursive(root, value);
		}

		void traversal() const {
			traversalRecursive(root);
			std::cout << std::endl;
		}

	private:
		TreeNode<T>* insertRecursive(TreeNode<T>* node, const T& value) {
			if (node == nullptr) {
				return new TreeNode<T>(value);
			}

			if (value < node->binaryTreeData) {
				node->left = insertRecursive(node->left, value);
			}
			else if (value > node->binaryTreeData) {
				node->right = insertRecursive(node->right, value);
			}

			return node;
		}

		bool searchRecursive(const TreeNode<T>* node, const T& value) const {
			if (node == nullptr) {
				return false;
			}

			if (value == node->binaryTreeData) {
				return true;
			}
			else if (value < node->binaryTreeData) {
				return searchRecursive(node->left, value);
			}
			else {
				return searchRecursive(node->right, value);
			}
		}

		void traversalRecursive(const TreeNode<T>* node) const {
			if (node == nullptr) {
				return;
			}

			traversalRecursive(node->left);
			std::cout << node->binaryTreeData << " ";
			traversalRecursive(node->right);
		}
	};
}

#endif BINARY_TREE_H