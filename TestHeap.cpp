//
// Created by vitor on 27/12/24.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Heap/Heap.cpp"

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

  Heap maxHeap(true);

  while (cliUser != "exit") {
    std::cout << ">> ";
    std::getline(std::cin, cliUser);

    auto [key, value] = splitCommand(cliUser);

    if (key == "--help") {
      std::cout << "--help    : see helper. \n";
      std::cout << "--p1      : see change priority exemple #1 [50 to 10]\n";
      std::cout << "--p2      : see change priority exemple #2 [21 to 36]\n";
      std::cout << "--i1      : see insert exemple #1 [47]\n";
      std::cout << "--r1      : see remove exemple #1 [50]\n";
      std::cout << "--c1      : see construct exemple #1 [7 5 12 4 8 9 3 14 1 15]\n";
      std::cout << "--o       : see ordenation exemple #1 [50 48 45 29 15 35 40 27 26 14 12 33 30 37 20 21 19 25]\n";
      std::cout << "--o       : see ordenation exemple #1 [7 5 12 4 8 9 3 14 1 15]\n";
      std::cout << "--a       : see all ordenation cases\n";
    }
  }
  return 0;
}


//    vector<int> heap;
//    const vector<int> values = {50, 48, 45, 29, 15, 35, 40, 27, 26, 14, 12, 33, 30, 37, 20, 21, 19, 25};
//
//    maxHeap.makeHeap(heap, values);
//    cout << "Heap: ";
//    maxHeap.showHeap(heap);
//
//    maxHeap.changePriority(heap, 1, 10);
//    cout << "Change priority (50 to 10): ";
//    maxHeap.showHeap(heap);
//
//    maxHeap.insert(heap, 47);
//    cout << "Insert 47: ";
//    maxHeap.showHeap(heap);
//
//    const int removed = maxHeap.remove(heap);
//    cout << "Remove root " << removed << endl;
//    cout << "Heap after remove: ";
//    maxHeap.showHeap(heap);
//
//    maxHeap.heapSort(heap);
//    cout << "Sorted array: ";
//    maxHeap.showHeap(heap);
//
