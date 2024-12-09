//
// Created by Vitor on 07/12/24.
//

#include <iostream>
#include <queue>

using namespace std;

/**
 * TODO: Add comments.
 */
struct TreeNode {
  int value;
  struct TreeNode* leftSon;
  struct TreeNode* rightSon;

  explicit TreeNode(const int value) : value(value), leftSon(nullptr), rightSon(nullptr) {}
};

/**
 * TODO: Add comments.
 */
TreeNode* insertNode(TreeNode* root, const int value) {
  if (root == nullptr) { return new TreeNode(value); }
  if (value < root->value) { root->leftSon = insertNode(root->leftSon, value); }
  else { root->rightSon = insertNode(root->rightSon, value); }
  return root;
}

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
bool search(TreeNode* root, const int value) {
  if (root == nullptr) { return false; }
  if (value == root->value) { return true; }
  if (value < root->value) { return search(root->leftSon, value); }
  if (value > root->value) { return search(root->rightSon, value); }
  return false;
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

int main() {
  TreeNode* root = nullptr;
  root = insertNode(root, 10);
  root = insertNode(root, 5);
  root = insertNode(root, 15);
  root = insertNode(root, 3);
  root = insertNode(root, 7);

  printTree(root);
  std::cout << std::endl;

  cout << "Pre-Order Traversal: ";
  preOrder(root);

  std::cout << std::endl;

  cout << "In-Order Traversal: ";
  inOrder(root);

  std::cout << std::endl;

  cout << "Pos-Order Traversal: ";
  postOrder(root);

  std::cout << std::endl;

  std::cout << "Level Order Traversal: ";
  levelOrder(root);

  std::cout << std::endl;

  if (search(root, 2)) {
    cout << "Value found\n";
  } else {
    cout << "Value not found\n";
  }
  return 0;
}