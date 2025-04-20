#include <iostream>
using namespace std;

class heap {
public:
    heap() {
        arr[0] = -1;
        size = 0;
    }
    
    int arr[100];
    int size = 0;

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] >= val) {
                return;
            } else {
                swap(arr[parent], arr[index]);
                index = parent;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }

    void deleterootinheap() {
        if (size == 0) {
            cout << "Nothing to delete";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size) {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            int largest = i;

            if (leftindex <= size && arr[leftindex] > arr[largest]) {
                largest = leftindex;
            }
            if (rightindex <= size && arr[rightindex] > arr[largest]) {
                largest = rightindex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }
};

// Function to heapify the given array
void heapify(int arr[], int size, int index) {
    int largest = index;
    int leftindex = 2 * index;
    int rightindex = 2 * index + 1;

    if (leftindex <= size && arr[leftindex] > arr[largest]) {
        largest = leftindex;
    }
    if (rightindex <= size && arr[rightindex] > arr[largest]) {
        largest = rightindex;
    }

    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapify(arr, size, largest); // Recursively heapify the affected subtree
    }
}

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout << endl;

    h.deleterootinheap();
    h.print();
    h.insert(56);
    cout << endl;
    h.print();

    // Array representing a heap
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Building the heap using heapify
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Printing heapified array: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
