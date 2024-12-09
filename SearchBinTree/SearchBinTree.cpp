//
// Created by vitor on 09/12/24.
//

#include "SearchBinTree.h"
#include <iostream>

using namespace std;

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
TreeNode* searchNode(TreeNode* root, int value, TreeNode** parent) {
    TreeNode* current = root;
    *parent = nullptr;

    while (current != nullptr) {
        if (current->value == value) { return current; }
        *parent = current;

        if (value < current->value) { current = current->leftSon; }
        else { current = current->rightSon; }
    }
    return nullptr;
}

/**
 * TODO: Add comments.
 */
TreeNode* findMin(TreeNode* root) {
    while (root->leftSon != nullptr) { root = root->leftSon; }
    return root;
}

/**
 * TODO: Add comments.
 */
TreeNode* deleteNode(TreeNode* root, const int value) {
    TreeNode* parent = nullptr;
    TreeNode* nodeToDelete = searchNode(root, value, &parent);

    if (nodeToDelete == nullptr) {
        cout << "Value not found!" << endl;
        return root;
    }

    // First case: No son's;
    if (nodeToDelete->leftSon == nullptr && nodeToDelete->rightSon == nullptr) {
        if (nodeToDelete == root) {
            delete root;
            return nullptr;
        }
        if (parent->leftSon == nodeToDelete) {
            parent->leftSon = nullptr;
        } else {
            parent->rightSon = nullptr;
        }
        delete nodeToDelete;
    }

    // Second case: One son.
    else if (nodeToDelete->leftSon == nullptr || nodeToDelete->rightSon == nullptr) {
        TreeNode* child = (nodeToDelete->leftSon != nullptr) ? nodeToDelete->leftSon : nodeToDelete->rightSon;

        if (nodeToDelete == root) { root = child; }
        else if (parent->leftSon == nodeToDelete) { parent->leftSon = child; }
        else { parent->rightSon = child; }

        delete nodeToDelete;
    }

    // Three case: Two sons.
    else {
        TreeNode* successor = findMin(nodeToDelete->rightSon);
        int successorValue = successor->value;
        root = deleteNode(root, successorValue);
        nodeToDelete->value = successorValue;
    }

    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 8);

    cout << "Tree: ";
    printTree(root);

    return 0;
}