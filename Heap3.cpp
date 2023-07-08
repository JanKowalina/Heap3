#include <iostream>
using namespace std;

void add(int heap[], int* leafCount, int value, int* oddEven) {
    // Add a value to the heap
    int leafIndex = *leafCount;
    heap[leafIndex] = value;

    // Adjust the heap to maintain the heap property
    while (leafIndex != 0) {
        if ((heap[(leafIndex - 1) / 2] < heap[leafIndex] && (*oddEven % 2) == 0) ||
            (heap[(leafIndex - 1) / 2] > heap[leafIndex] && (*oddEven % 2) == 1)) {
            int temp = heap[(leafIndex - 1) / 2];
            heap[(leafIndex - 1) / 2] = heap[leafIndex];
            heap[leafIndex] = temp;
        }
        leafIndex = (leafIndex - 1) / 2;
    }
}

void heapify(int heap[], int* leafCount, int index, int* oddEven) {
    // Rearrange the heap to maintain the heap property
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if ((*oddEven % 2) == 0) {
        if (left < *leafCount && heap[left] > heap[largest])
            largest = left;
        if (right < *leafCount && heap[right] > heap[largest])
            largest = right;
    } else {
        if (left < *leafCount && heap[left] < heap[largest])
            largest = left;
        if (right < *leafCount && heap[right] < heap[largest])
            largest = right;
    }

    if (index != largest) {
        int temp = heap[largest];
        heap[largest] = heap[index];
        heap[index] = temp;
        heapify(heap, leafCount, largest, oddEven);
    }
}

void buildHeap(int heap[], int* leafCount, int* oddEven) {
    // Build a heap from an array
    int firstLeaf = *leafCount / 2 - 1;
    for (int i = firstLeaf; i >= 0; i--)
        heapify(heap, leafCount, i, oddEven);
}

int remove(int heap[], int* leafCount, int* oddEven) {
    // Remove and return the root element from the heap
    (*leafCount)--;
    int removed = heap[*leafCount];
    heap[*leafCount] = heap[0];
    heap[0] = removed;
    heapify(heap, leafCount, 0, oddEven);
    return removed;
}

void reverseHeap(int heap[], int* leafCount, int* oddEven) {
    // Reverse the order of elements in the heap
    int firstLeaf = *leafCount / 2 - 1;
    for (int i = firstLeaf; i >= 0; i--)
        heapify(heap, leafCount, i, oddEven);
}

int main() {
    int* heap = new int[10000];
    int heapSize = 10000;
    int leafCount = 0;
    int value, oddEven = 0;

    while (cin) {
        char command;
        cin >> command;
        switch (command) {
            case '+':
                // Add value to the heap
                cin >> value;
                add(heap, &leafCount, value, &oddEven);
                leafCount++;
                break;
            case '-':
                // Remove and print the root element
                if (leafCount != 0)
                    cout << remove(heap, &leafCount, &oddEven) << endl;
                break;
            case 'p':
                // Print the elements in the heap
                for (int i = 0; i < leafCount; i++) {
                    cout << heap[i] << " ";
                }
                cout << endl;
                break;
            case 'r':
                // Read elements and build a heap
                int length;
                cin >> length;
                if (length <= heapSize) {
                    for (int i = 0; i < length; i++)
                        cin >> heap[i];

                    leafCount = length;
                    buildHeap(heap, &leafCount, &oddEven);
                }
                break;
            case 's':
                // Reverse the heap order
                oddEven++;
                reverseHeap(heap, &leafCount, &oddEven);
                break;
            case 'q':
                // Free memory and exit the program
                delete[] heap;
                return 0;
                break;
        }
    }
    delete[] heap;
    return 0;
}
