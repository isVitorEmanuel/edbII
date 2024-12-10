//
// Created by vitor on 09/12/24.
//

#include <iostream>

#include "SearchBinTree.h"

using namespace std;

/**
 * Inserts a new node with the given value into the binary search tree.
 * If the tree is empty, a new node is created as the root.
 * Otherwise, it finds the appropriate position for the new node.
 * @param root The root node of the tree.
 * @param value The value to be inserted.
 * @return The updated root of the tree.
 */
TreeNode* insertNode(TreeNode* root, const int value) {
    if (root == nullptr) { return new TreeNode(value); }
    if (value < root->value) { root->leftSon = insertNode(root->leftSon, value); }
    else { root->rightSon = insertNode(root->rightSon, value); }
    return root;
}

/**
 * Searches for a node with the given value in the binary search tree.
 * Returns true if the value is found, otherwise returns false.
 * @param root The root node of the tree.
 * @param value The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool search(TreeNode* root, const int value) {
    if (root == nullptr) { return false; }
    if (value == root->value) { return true; }
    if (value < root->value) { return search(root->leftSon, value); }
    if (value > root->value) { return search(root->rightSon, value); }
    return false;
}

/**
 * Searches for a node with the given value and its parent in the binary search tree.
 * @param root The root node of the tree.
 * @param value The value to search for.
 * @param parent A pointer to store the parent of the found node.
 * @return A pointer to the node if found, nullptr if not found.
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
 * Finds the minimum value node in the binary search tree.
 * The minimum value node is the leftmost node in the tree.
 * @param root The root node of the tree.
 * @return A pointer to the node with the minimum value.
 */
TreeNode* findMin(TreeNode* root) {
    while (root->leftSon != nullptr) { root = root->leftSon; }
    return root;
}

/**
 * Deletes a node with the given value from the binary search tree.
 * Handles three cases:
 * 1. Node has no children (leaf node).
 * 2. Node has one child.
 * 3. Node has two children (finds in-order successor and deletes it).
 * @param root The root node of the tree.
 * @param value The value to be deleted.
 * @return The updated root of the tree.
 */
TreeNode* deleteNode(TreeNode* root, const int value) {
    TreeNode* parent = nullptr;
    TreeNode* nodeToDelete = searchNode(root, value, &parent);

    if (nodeToDelete == nullptr) {
        cout << "Value not found!" << endl;
        return root;
    }

    // First case: No children (leaf node).
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

    // Second case: One child.
    else if (nodeToDelete->leftSon == nullptr || nodeToDelete->rightSon == nullptr) {
        TreeNode* child = (nodeToDelete->leftSon != nullptr) ? nodeToDelete->leftSon : nodeToDelete->rightSon;

        if (nodeToDelete == root) { root = child; }
        else if (parent->leftSon == nodeToDelete) { parent->leftSon = child; }
        else { parent->rightSon = child; }

        delete nodeToDelete;
    }

    // Third case: Two children (find the in-order successor and delete it).
    else {
        TreeNode* successor = findMin(nodeToDelete->rightSon);
        int successorValue = successor->value;
        root = deleteNode(root, successorValue);
        nodeToDelete->value = successorValue;
    }

    return root;
}

/**
 * Checks if the binary tree is a valid binary search tree using in-order traversal.
 * Ensures that each node's value is greater than the value of its predecessor in the traversal.
 * @param root The root node of the tree.
 * @param prev A pointer to store the previous node during traversal.
 * @return true if the tree is a valid binary search tree, false otherwise.
 */
bool isBSTInOrder(TreeNode* root, TreeNode*& prev) {
    if (root == nullptr) { return true; }
    if (!isBSTInOrder(root->leftSon, prev)) { return false; }
    if (prev != nullptr && root->value <= prev->value) { return false; }
    prev = root;
    return isBSTInOrder(root->rightSon, prev);
}

/**
 * Wrapper function to check if the binary tree is a valid binary search tree.
 * Calls the isBSTInOrder function to validate the tree.
 * @param root The root node of the tree.
 * @return true if the tree is a valid binary search tree, false otherwise.
 */
bool isBinarySearchTree(TreeNode* root) {
    TreeNode* prev = nullptr;
    return isBSTInOrder(root, prev);
}
