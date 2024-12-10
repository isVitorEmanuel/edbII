//
// Created by Vitor on 07/12/24.
//

#include "Tree.h"

#include <iostream>
#include <queue>

using namespace std;

/**
 * Constructor for the TreeNode class.
 * Initializes the value of the node and sets the left and right child pointers to nullptr.
 */
TreeNode::TreeNode(int value) : value(value), leftSon(nullptr), rightSon(nullptr) {}

/**
 * Performs a pre-order traversal of the binary tree.
 * Visits the current node first, then the left subtree, and finally the right subtree.
 * @param root Pointer to the root of the tree.
 */
void preOrder(TreeNode* root) {
  std::cout << root->value << " ";
  if (root->leftSon != nullptr) { preOrder(root->leftSon); }
  if (root->rightSon != nullptr) { preOrder(root->rightSon); }
}

/**
 * Performs an in-order traversal of the binary tree.
 * Visits the left subtree first, then the current node, and finally the right subtree.
 * @param root Pointer to the root of the tree.
 */
void inOrder(TreeNode* root) {
  if (root->leftSon != nullptr) { inOrder(root->leftSon); }
  std::cout << root->value << " ";
  if (root->rightSon != nullptr) { inOrder(root->rightSon); }
}

/**
 * Performs a post-order traversal of the binary tree.
 * Visits the left subtree first, then the right subtree, and finally the current node.
 * @param root Pointer to the root of the tree.
 */
void postOrder(TreeNode* root) {
  if (root->leftSon != nullptr) { postOrder(root->leftSon); }
  if (root->rightSon != nullptr) { postOrder(root->rightSon); }
  std::cout << root->value << " ";
}

/**
 * Performs a level-order traversal of the binary tree.
 * Visits nodes level by level, starting from the root.
 * @param root Pointer to the root of the tree.
 */
void levelOrder(TreeNode* root) {
  if (root == nullptr) { return; }

  queue<TreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();

    std::cout << node->value << " ";

    if (node->leftSon != nullptr) { q.push(node->leftSon); }
    if (node->rightSon != nullptr) { q.push(node->rightSon); }
  }
}

/**
 * Prints the tree in a formatted manner.
 * Displays the root node and its children (left and right) recursively.
 * If a node has no children, it won't print anything for that side.
 * @param root Pointer to the root of the tree.
 */
void printTree(TreeNode* root) {
  if (root == nullptr) {
    std::cout << "Empty tree";
    return;
  }

  cout << "(" << root->value;

  if (root->leftSon != nullptr || root->rightSon != nullptr) {
    cout << " ";

    if (root->leftSon != nullptr) {
      cout << "[L: ";
      printTree(root->leftSon);
      cout << "]";
    }

    if (root->rightSon != nullptr) {
      cout << " [R: ";
      printTree(root->rightSon);
      cout << "]";
    }
  }
  cout << ")";
}
