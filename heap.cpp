#include <iostream>
#include <vector>

using namespace std;

// Heapify function to maintain heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    // Example usage
    vector<int> studentIDs = {24, 67, 7, 8, 5, 335, 6};

    cout << "Unsorted student IDs: ";
    for (int id : studentIDs) {
        cout << id << " ";
    }
    cout << endl;

    // Time complexity: O(n log n) for all cases
    // Space complexity: O(1) - in-place sorting algorithm
    heapSort(studentIDs);

    cout << "Sorted student IDs: ";
    for (int id : studentIDs) {
        cout << id << " ";
    }
    cout << endl;

    return 0;
}
