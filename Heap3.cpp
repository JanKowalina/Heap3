#include <iostream>
using namespace std;

void add(int heap[], int* leafCount, int value, int* oddEven) {
    int leafIndex = *leafCount;
    heap[leafIndex] = value;

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
    int firstLeaf = *leafCount / 2 - 1;
    for (int i = firstLeaf; i >= 0; i--)
        heapify(heap, leafCount, i, oddEven);
}

int remove(int heap[], int* leafCount, int* oddEven) {
    (*leafCount)--;
    int removed = heap[*leafCount];
    heap[*leafCount] = heap[0];
    heap[0] = removed;
    heapify(heap, leafCount, 0, oddEven);
    return removed;
}

void reverseHeap(int heap[], int* leafCount, int* oddEven) {
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
                cin >> value;
                add(heap, &leafCount, value, &oddEven);
                leafCount++;
                break;
            case '-':
                if (leafCount != 0)
                    cout << remove(heap, &leafCount, &oddEven) << endl;
                break;
            case 'p':
                for (int i = 0; i < leafCount; i++) {
                    cout << heap[i] << " ";
                }
                cout << endl;
                break;
            case 'r':
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
                oddEven++;
                reverseHeap(heap, &leafCount, &oddEven);
                break;
            case 'q':
                delete[] heap;
                return 0;
                break;
        }
    }
    delete[] heap;
    return 0;
}
