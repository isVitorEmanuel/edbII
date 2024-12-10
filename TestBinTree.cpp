//
// Created by vitor on 10/12/24.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Tree.h"
#include "SearchBinTree/SearchBinTree.h"

/**
 * This function splits the input string entered by the user and converts it
 * into a <command, value> pair
 *
 * @param input The string command digitized by user.
 * @return A pair with key (command flag) and value.
 */
std::pair<std::string, std::string> splitCommand(const std::string& input) {
  std::istringstream iss(input);
  std::string key;
  std::string value;

  iss >> key;
  iss >> value;

  return {key, value};
}

int main() {
  std::string cliUser;                          //<- Input user.
  TreeNode *root = nullptr;                     //<- A TreeNode to root.

  /** Uncomment this line to add nodes default.
    root = insertNode(root, 22);
    root = insertNode(root, 23);
    root = insertNode(root, 30);
    root = insertNode(root, 21);
    root = insertNode(root, 18);
    root = insertNode(root, 17);
    root = insertNode(root, 10);
    root = insertNode(root, 15);
  */

  while (cliUser != "exit") {
    std::cout << ">> ";
    std::getline(std::cin, cliUser);

    auto [key, value] = splitCommand(cliUser);

    if (key == "--help") {
      std::cout << "--help   : see helper. \n";
      std::cout << "--s      : show tree\n";
      std::cout << "--s-in   : show tree in order\n";
      std::cout << "--s-pre  : show tree pre-order\n";
      std::cout << "--s-pos  : show tree pos-order\n";
      std::cout << "--s-lev  : show tree level-order\n";
      std::cout << "--i      : insert node in tree\n";
      std::cout << "           --i [value]\n";
      std::cout << "--d      : delete node in tree\n";
      std::cout << "           --d [value]\n";
      std::cout << "--f      : check if node is in tree\n";
      std::cout << "           --f [value]\n";
      std::cout << "--is-bin: check i f tree is binary tree\n";
    }

    if (key == "--s") {
      printTree(root);
      std::cout << std::endl;
    }

    if (key == "--s-in") {
      inOrder(root);
      std::cout << std::endl;
    }

    if (key == "--s-pre") {
      preOrder(root);
      std::cout << std::endl;
    }

    if (key == "--s-pos") {
      postOrder(root);
      std::cout << std::endl;
    }

    if (key == "--s-lev") {
      levelOrder(root);
      std::cout << std::endl;
    }

    if (key == "--i") { root = insertNode(root, stoi(value)); }

    if (key == "--d") { root = deleteNode(root, stoi(value)); }

    if (key == "--f") {
      if (search(root, stoi(value)) == true) {
        std::cout << "True\n";
      } else {
        std::cout << "False\n";
      }
    }

    if (key == "--is-bin") {
      if (isBinarySearchTree(root)) {
        std::cout << "True\n";
      } else {
        std::cout << "False\n";
      }
    }
  }

  return 0;
}
