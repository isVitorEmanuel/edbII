//
// Created by Vitor on 07/12/24.
//

#include "Tree.h"

#include <iostream>
#include <queue>

using namespace std;

/**
 * TODO: Add comments.
 */
TreeNode::TreeNode(int value) : value(value), leftSon(nullptr), rightSon(nullptr) {}

/**
 * TODO: Add comments.
 */
void preOrder(TreeNode* root) {
  std::cout << root->value << " ";
  if (root->leftSon != nullptr) { preOrder(root->leftSon); }
  if (root->rightSon != nullptr) { preOrder(root->rightSon); }
}

/**
 * TODO: Add comments.
 */
void inOrder(TreeNode* root) {
  if (root->leftSon != nullptr) { inOrder(root->leftSon); }
  std::cout << root->value << " ";
  if (root->rightSon != nullptr) { inOrder(root->rightSon); }
}

/**
 * TODO: Add comments.
 */
void postOrder(TreeNode* root) {
  if (root->leftSon != nullptr) { postOrder(root->leftSon); }
  if (root->rightSon != nullptr) { postOrder(root->rightSon); }
  std::cout << root->value << " ";
}

/**
 * TODO: Add comments.
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
 * TODO: Add comments.
 */
void printTree(TreeNode* root) {
  if (root == nullptr) { return; }

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