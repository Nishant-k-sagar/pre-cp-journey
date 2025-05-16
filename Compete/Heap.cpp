#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i in max heap
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i ; // left child index
    int right = 2 * i + 1; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Function to heapify a subtree rooted at index i in min heap
void minHeapify(vector<int>& arr, int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i ; // left child index
    int right = 2 * i + 1; // right child index

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        minHeapify(arr, n, smallest);
    }
}

// Main function to do heap sort
void heapSortMin(vector<int>& arr) {
    int n = arr.size();

    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call min heapify on the reduced heap
        minHeapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Max Heap Sort
    heapSort(arr);
    cout << "Sorted array (Max Heap Sort): ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Min Heap Sort
    // heapSortMin(arr);
    // cout << "Sorted array (Min Heap Sort): ";
    // for (int i = 0; i < n; ++i)
    //     cout << arr[i] << " ";
    // cout << endl;

    return 0;
}
