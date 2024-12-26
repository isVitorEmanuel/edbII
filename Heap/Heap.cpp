#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMaxHeap;

    bool compare(const int parent, const int child) const {
        return isMaxHeap ? parent < child : parent > child;
    }

    void heapifyUp(const int index) {
        if (index > 1) {
            if (const int parent = index / 2; compare(heap[parent], heap[index])) {
                swap(heap[parent], heap[index]);
                heapifyUp(parent);
            }
        }
    }

    void heapifyDown(const int index) {
        const int size = heap.size() - 1;
        const int left = 2 * index;
        const int right = left + 1;
        int largest = index;

        if (left <= size && compare(heap[largest], heap[left])) {
            largest = left;
        }
        if (right <= size && compare(heap[largest], heap[right])) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }


public:
    explicit Heap(const bool maxHeap = true) : isMaxHeap(maxHeap) { heap.push_back(0); }

    void insert(const int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int remove() {
        if (heap.size() <= 1) {
            throw runtime_error("Heap is empty!");
        }
        const int root = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(1);
        return root;
    }

    void changePriority(const int index, const int newValue) {
        if (index < 1 || index >= heap.size()) {
            throw out_of_range("Out of range!");
        }
        const int oldValue = heap[index];
        heap[index] = newValue;

        if (compare(oldValue, newValue)) {
            std::cout << "HeapUp\n";
            heapifyUp(index);
        } else {
            std::cout << "HeapDown\n";
            heapifyDown(index);
        }
    }

    void makeHeap(const vector<int>& arr) {
        heap = {0};
        heap.insert(heap.end(), arr.begin(), arr.end());

        for (int i = (heap.size() - 1) / 2; i >= 1; --i) {
            heapifyDown(i);
        }
    }

    void showHeap() const {
        for (size_t i = 1; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap maxHeap(true); // Max-heap
    const vector<int> values = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    maxHeap.makeHeap(values);
    cout << "Heap: ";
    maxHeap.showHeap();

    maxHeap.insert(15);
    cout << "Insert 15: ";
    maxHeap.showHeap();

    maxHeap.changePriority(1, 11);
    cout << "Change priority (16 to 11): ";
    maxHeap.showHeap();

    const int removed = maxHeap.remove();
    cout << "Remove root " << removed << endl;
    cout << "Heap after remove: ";
    maxHeap.showHeap();

    return 0;
}


