//
// Created by vitor on 09/12/24.
//

#ifndef SEARCHBINTREE_H
#define SEARCHBINTREE_H
#include "../Tree.h"

TreeNode* insertNode(TreeNode* root, int value);
bool search(TreeNode* root, int value);
TreeNode* searchNode(TreeNode* root, int value, TreeNode** parent);
TreeNode* findMin(TreeNode* root);
TreeNode* deleteNode(TreeNode* root, int value);
#endif //SEARCHBINTREE_H
