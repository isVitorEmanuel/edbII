#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

class Heap {

private:
    bool isMaxHeap;

    bool compare(const int parent, const int child) const {
        return isMaxHeap ? parent < child : parent > child;
    }

    void heapifyUp(vector<int>& heap, const int index) {
        if (index > 1) {
            if (const int parent = index / 2; compare(heap[parent], heap[index])) {
                swap(heap[parent], heap[index]);
                heapifyUp(heap, parent);
            }
        }
    }

    void heapifyDown(vector<int>& heap, const int index, const int size = -1) {
        const int effectiveSize = (size == -1) ? heap.size() - 1 : size;
        const int left = 2 * index;
        const int right = left + 1;
        int largest = index;

        if (left <= effectiveSize && compare(heap[largest], heap[left])) {
            largest = left;
        }

        if (right <= effectiveSize && compare(heap[largest], heap[right])) {
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(heap, largest, effectiveSize);
        }
    }

public:
    explicit Heap(const bool maxHeap = true) : isMaxHeap(maxHeap) {}

    void makeHeap(vector<int>& heap, const vector<int>& arr) {
        heap = {0};
        heap.insert(heap.end(), arr.begin(), arr.end());

        for (int i = (heap.size() - 1) / 2; i >= 1; --i) {
            heapifyDown(heap, i);
        }
    }

    void insert(vector<int>& heap, const int value) {
        heap.push_back(value);
        heapifyUp(heap, heap.size() - 1);
    }

    int remove(vector<int>& heap) {
        if (heap.size() <= 1) {
            throw runtime_error("Heap is empty!");
        }

        const int root = heap[1];

        heap[1] = heap.back();
        heap.pop_back();
        heapifyDown(heap, 1);
        return root;
    }

    void changePriority(vector<int>& heap, const int index, const int newValue) {
        if (index < 1 || index >= heap.size()) {
            throw out_of_range("Out of range!");
        }

        const int oldValue = heap[index];
        heap[index] = newValue;

        if (compare(oldValue, newValue)) {
            heapifyUp(heap, index);
        } else {
            heapifyDown(heap, index);
        }
    }

    static void showHeap(const vector<int>& heap) {
        for (size_t i = 1; i < heap.size(); ++i) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void heapSort(vector<int>& arr) {
        vector<int> heap;
        makeHeap(heap, arr);

        for (int i = arr.size() - 1; i >= 0; --i) {
            arr[i] = heap[1];
            heap[1] = heap[heap.size() - 1];
            heap.pop_back();
            heapifyDown(heap, 1, heap.size() - 1);
        }

    }
};
